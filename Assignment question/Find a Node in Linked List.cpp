/*You have been given a singly linked list of integers.
Write a function that returns the index/position of integer data denoted by 'N' (if it exists).
Return -1 otherwise.

Note :
Assume that the Indexing for the singly linked list always starts from 0.

Sample Input 1 :
2
3 4 5 2 6 1 9 -1
5
10 20 30 40 50 60 70 -1
6
Sample Output 1 :
2
-1
 Explanation for Sample Output 1:
In test case 1, 'N' = 5 appears at position 2 (0-based indexing) in the given linked list.

In test case 2, we can see that 'N' = 6 is not present in the given linked list.
Sample Input 2 :
2
1 -1
2
3 4 5 2 6 1 9 -1
6
Sample Output 2 :
-1
4
 Explanation for Sample Output 2:
In test case 1, we can see that 'N' = 2 is not present in the given linked list.

In test case 2, 'N' = 6 appears at position 4 (0-based indexing) in the given linked list.
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



/// idea: run in a loop, till head is NULL. Create a count variabke to keep track of index,
/// if the data of the head is n return count, also keep updating head, so as to use head->data with every iteration in loop.



/// Our program to write here.
int findNode(Node *head, int n){
    int count =0;
    while(head!=NULL){
        if(head->data==n){
        return count;}
        count++;
        head=head->next;
    }
    return -1;
}






int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNode(head, val) << endl;
	}
}
