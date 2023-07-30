#include <iostream>
#include"Node.cpp"
using namespace std;

Node *takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
        head = newNode;
        tail = newNode;
        }else{
        tail->next = newNode;
        tail=tail->next;
        ///or
        /// tail = newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    Node *head = takeInput();
    print(head);
}

