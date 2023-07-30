/*You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.
Note :
Try solving this in O(1) auxiliary space.

No need to print the list, it has already been taken care.
/*Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the first sorted singly linked list separated by a single space.

The second line of the input contains the elements of the second sorted singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output :
For each test case/query, print the resulting sorted singly linked list, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t = 10^2
0 <= N <= 10 ^ 4
0 <= M <= 10 ^ 4
Where N and M denote the sizes of the singly linked lists.

Time Limit: 1sec
Sample Input 1 :
1
2 5 8 12 -1
3 6 9 -1
Sample Output 1 :
2 3 5 6 8 9 12
Sample Input 2 :
2
2 5 8 12 -1
3 6 9 -1
10 40 60 60 80 -1
10 20 30 40 50 60 90 100 -1
Sample Output 2 :
2 3 5 6 8 9 12
10 10 20 30 40 40 50 60 60 60 80 90 100
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




/// time comp - O(m+n)
/// space - O(1)
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    if(head1==NULL) { return head2;}
    if(head2==NULL) {return head1;}
    Node *newhead = NULL, *newtail = NULL;  /// where they will point depends which list's first element is small
    if(head1->data < head2->data){
        newhead =head1;
        newtail = head1;
        head1=head1->next; /// since we know which is small we shift the head1 in this statement itself
    }
    else  /// else statement is also important
    {
        newhead = head2;
        newtail = head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){ /// this && is important, if anyone is NULL then we chnage the way we merge the two LL
        if(head1->data < head2->data){
            newtail->next= head1;  /// newtail is at node1, newtail->next is where we connect the second node and value we put there is of head1
            newtail = newtail->next;
            head1=head1->next;
        }
        else{
            newtail->next=head2;
            newtail = newtail->next;
            head2=head2->next;
        }
    }
    if(head1!=NULL){
        newtail->next=head1; /// this line is enough, no need to write head=head->next, coz its a linked list rest of the list is already connected
        /// so no need to make new connection
    }
    if(head2!=NULL){
        newtail->next=head2;
    }
    return newhead;
}


using namespace std;
//#include "solution.h"

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
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}




