#include <iostream>

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;


Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}



/// Inseting program ///
Node* insertNode(Node *head, int i, int data){
    if(head==NULL){
    return head;}
    if(i==0){
    Node *newNode = new Node(data);
    newNode->next = head;
    head=newNode;}
    else if(i==1){
    Node *newNode= new Node(data);
    Node *temp = head->next;
    head->next=newNode;
    newNode->next = temp;
    return head;}
    else{
        insertNode(head->next, i-1, data); /// beacuse we use recursion its important to use the 'return head;' statement.
        return head;                       /// so the head is changed from 0th index to next index.

        /// linked list is printed using its head only, thats also a reason that we need to return "head".
    }
}




void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }
}
