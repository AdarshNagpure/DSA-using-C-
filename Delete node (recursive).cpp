/*Given a singly linked list of integers and position 'i', delete the node present at the 'i-th' position in the linked list recursively

Assume that the Indexing for the linked list always starts from 0.
No need to print the list, it has already been taken care. Only return the new head to the list.

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Sample Input 2 :
2
30 -1
0
10 20 30 50 60 -1
4
Sample Output 2 :
10 20 30 50
*/


#include <iostream>
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}







/// Our delete program ///
Node *deleteNodeRec(Node *head, int pos){
    if(head==NULL){
    return head;}
    if(pos==0){
    Node *temp = head; /// saves the updated head, head also shifts till i==1, new head is saved in temp.
    head=head->next;
    delete temp;
    return head;}

    Node *smallhead = deleteNodeRec(head->next, pos-1); /// its a pointer that points to a recursion call.
    head->next = smallhead; /// this is an important step. head->next is the address of next node, we see recursion is called on that address.
                            /// in recursion we write head->next (we call from next node), hence this line is important,
                            /// we call recursion on next node as well.
    return head;
}







/// Method 2, better not to use this but idea samajh lo
/*
Node *deleteNodeRec(Node *head, int pos) {
	if(head->next==NULL){
		return NULL;
	}
	if(pos==0){
		Node* temp=head->next;
		head->next = NULL;
		delete head;
		return temp;
	}
	if(pos==1){
		Node *temp=head->next;
		head->next = temp->next;
		temp->next=NULL;
		delete temp;
		return head;
	}
        Node *node_x = deleteNodeRec(head->next, pos-1);
		return head;
}
*/




void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNodeRec(head, pos);
		print(head);
	}

	return 0;
}
