/// Question
/*You have been given a singly linked list of integers along with an integer 'N'.
Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
Time Limit: 1sec for the program to work
Sample Input 1 :
2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5
Sample Output 1 :
3 4 5 1 2
20 30 40 50 60 10
Sample Input 2 :
1
10 6 77 90 61 67 100 -1
4
Sample Output 2 :
90 61 67 100 10 6 77

Explanation to Sample Input 2 :
We have been required to move the last 4 nodes to the front of the list. Here, "90->61->67->100" is the list which
represents the last 4 nodes. When we move this list to the front then the remaining part of the initial list which is, "10->6->77" is
attached after 100. Hence, the new list formed with an updated head pointing to 90.
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
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}



/// Idea: first traverse from head, place three new pointers (new head, new tail, tail(at last pointer)), newtail pe null lagana hai,
///  old tail ko old head se connect karna hai, and finally return new head.

/// our main program to write.
/*int length(Node *head){  /// method 1
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}*/
/// OR
int length(Node *head){   /// method 2
    if(head==NULL){
    return 0;}else{
        return 1+length(head->next);
    }
}
Node *appendLastNToFirst(Node *head, int n){
    if(head==NULL || n==0){
    return head;}

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
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}
