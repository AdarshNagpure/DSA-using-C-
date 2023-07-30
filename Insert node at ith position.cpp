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

Node* insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);
    int count=0;
    Node *temp=head;


    /// But for handling the 0th index we need another condition, we need to handle it in another way.
    if(i==0){
        newNode -> next = head; /// new node to insert ho gayi.
        head = newNode;   ///head ko bhi update kar dena hai hame abhi, yaha local head me change hua, main ke head me abhi bhi old address hai
        /// change that too, return this updated value to main.
    }
    while(temp!=NULL &&count<i-1){ /// temp statement helpes when value of (i) is more than the length of the list, that time we jump out of loop.
        temp = temp -> next;
        count++;
    }
    if(temp!=NULL){  ///ye if statement zaruri hai coz isse program bina crash hue ham bahar aa jaayenge, kab? jab hamari (i) ki value length se zyad badi ho!
    /// Connecting the new inserted node to the rest of the link list.
    Node *a = temp->next;   ///these lines to be executed when temp has reached the correct node.
    temp->next = newNode;
    newNode -> next = a;
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
    int i, data;
    cin>>i>>data;
    head = insertNode(head, i, data);
    print(head);
}

