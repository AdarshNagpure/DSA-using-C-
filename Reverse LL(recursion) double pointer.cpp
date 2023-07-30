#include <iostream>
using namespace std;
#include "Node.cpp"
/// time complexity is O(n)
class Pair{
    public:
    Node *head;
    Node *tail;
};

Pair reverseLL_2(Node *head){
    if(head==NULL && head->next==NULL){
        Pair ans;
        ans.head = head;      /// ans ke do properties hai head and tail, access point (.) use karke use karte hai
        ans.tail = head; /// if size is one then ans ke both head, tail me head hona chahiye
        return ans;
    }
     Pair smallAns = reverseLL_2(head -> next);   /// reverse list ka answer, isme smallAns me jaake save ho jaayega
    /// now just need to add the first element to the last of this linked list
    /// smallAns has the tail of reversed list(as the head is traversing, head->next)
    smallAns.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node* reverseLL_Better(Node *head){
    return reverseLL_2(head).head; /// pair class ka object aaya but hame bas head return karna hai, so isiliye wed did .head
    /// return only head not tail
}

Node* reverseLL(Node *head) {
	if(head == NULL || head -> next == NULL) {
		return head;
	}

	Node *smallAns = reverseLL(head -> next); /// saving the head of first ele of reversed LL

	Node *temp = smallAns;
	while(temp -> next != NULL) {
		temp = temp -> next;
	}/// coming out of this temp ke pass reversed LL ke last ele ka address hoga

	temp -> next = head; /// now connect that to our head
	head -> next = NULL;
	return smallAns;
}

Node* takeInput_Better() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
			// OR
			// tail = newNode;
		}

		cin >> data;
	}
	return head;
}

void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

int main() {

	Node *head = takeInput_Better();
	head = reverseLL(head);
	print(head);
}
