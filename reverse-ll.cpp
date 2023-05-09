#include <iostream>
using namespace std;

// creating a user defined datatype for a LL node
class Node
{
public:
    int value;
    Node *next;

    Node()
    {
        this->value = -1;
        this->next = NULL;
    }
};
void printList(Node *temp)
{
    // how to traverse in a LL using next.
    if (temp == NULL)
    {
        cout << "no element";
    }
    while (temp != NULL)
    {

        cout << " -> "<< temp->value ;
        temp = temp->next;
    }
    cout<<endl;
}
void insertAtFront(Node **headref, int val)
{
    Node *newNode = new Node();
    newNode->value = val;
    newNode->next = (*headref);
    *headref = newNode;
}

void reverse(Node** head){
    //creating 3 nodes to store the locations in pointers
    if((*head)==NULL){return;}
    if((*head)->next==NULL){return;}

    Node* prev;
    Node* curr;
    Node* forw;
    prev=NULL;
    curr=*head;
    forw=curr->next;

    while(curr!=NULL){

    curr->next=prev;
    prev=curr;
    curr=forw;

    if(forw!=NULL){
        /*The line if(forw->next!=NULL){ forw=forw->next; } assumes that forw is not NULL, which is not guaranteed. This could lead to a segmentation fault if forw is NULL.*/
    forw=forw->next;}
    }

    *head=prev;
}

int main()
{
    // creating the pointers to the nodes.
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    // assinging the values to the pointers
    head->value = 1;
    second->value = 10;
    third->value = 100;
    // linking the nodes using the pointer
    head->next = second;
    second->next = third;
    third->next = NULL;
    insertAtFront(&head,12);
    insertAtFront(&head,2);
    insertAtFront(&head,6);
    insertAtFront(&head,7);

    printList(head);
    reverse(&head);
    printList(head);
}