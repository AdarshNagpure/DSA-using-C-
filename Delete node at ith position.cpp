#include <iostream>
#include <bits/stdc++.h>
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
///#include "solution.h"

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
int length(Node *head) {
    if(head == NULL){
		return 0;
	}
	else{
		return 1+length(head->next);
	}
}
Node *deleteNode(Node *head, int pos)
{
   if(pos==0){
        Node *temp=head->next;
        delete head;
        return temp;
    }
    int c=1;
    Node* cur=head->next;
    Node* prev=head;
    while(cur!=NULL){
        if(c==pos){
            prev->next=cur->next;
            delete cur;
            return head;
        }
        prev=cur;
        cur=cur->next;
        c++;
    }
    return head;
}

/// Method 2 is
/*
Node *deleteNode(Node *head, int pos)
{
	int i=0;
	Node *current=head;
	if(head==NULL)
	{
		return head;
	}
	if(pos==0)
	{
		head=current->next;
		delete current;
		return head;
	}
	while(i<pos-1 && current->next!=NULL)
	{
		current = current->next;
		i++;
	}
	if(current->next != NULL)
	{
		Node *temp=current->next->next;
		delete current->next;
		current->next=temp;
	}
	return head;
}
*/

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        cout << length(head) << "\n";
    }
}






