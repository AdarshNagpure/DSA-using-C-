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
///#include "solution.h"

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

/*void printIthNode(Node *head, int i) ///
{
  Node *cursor =head;
  if(cursor=NULL){return;}
  while (cursor != NULL) {
    cursor = cursor->next;
  }
  cout << cursor->data;
  // return cursor->data;
}*/

 ///this is what iu need to code!!!!
void printIthNode(Node *head, int i){
    Node *temp=head;
    int count =0;
    while(count != i && temp!=NULL){
        temp = temp->next;
        count++;
    }
    if(count == i && temp!=NULL){ ///temp!=NULL is most imp[ortant line here !!!!
    cout<<temp->data;
    }
}///overall approach is good for thinking

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}
