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

void insertAfterND(Node *prev, int val){
    if(prev==NULL){cout<<"invalid arg";}

    Node* newNode = new Node();
    newNode->value=val;

    newNode->next=prev->next;
    prev->next=newNode;
}

void insertAfterVal(Node **head, int val,int after){
    if(*head==NULL){cout<<"emptyList";}

    Node* newNode=new Node();
    newNode->value=val;

    Node* temptraverser=*head;
    while(temptraverser!=NULL){
        if(temptraverser->value==after){
            newNode->next=temptraverser->next;
            temptraverser->next=newNode;
            return;
        }
        temptraverser=temptraverser->next;
    }
    cout<<"not found";
}

void insertAtLast(Node **head, int val)
{

    Node *newNode = new Node();
    newNode->value = val;
    newNode->next = NULL;
    //checking if the LL is empty or not
    if (*head==NULL){
        *head=newNode;
    }
    //declaring a pointer to traverse and find the value for the last node
    //intilized by the value of head
    Node*last = *head;
    while (last->next!= NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

void insertAtFront(Node **headref, int val)
{
    Node *newNode = new Node();
    newNode->value = val;
    newNode->next = (*headref);
    *headref = newNode;
}

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

    // printList(head);cout<<"intital";
    // insertAtFront(&head, 29);cout<<"\nadding at front ";
    // cout << endl;
    printList(head);
    insertAfterND(head,5);
    insertAfterND(second,56);
    printList(head);

    // insertAtLast(&head, 45);cout<<"\nadding at last   ";
    // cout << endl;
    // printList(head);

    // insertAfter(&head,34,10);cout<<"\nadding after last   "<<endl;
    // printList(head);

    // insertAfterVal(&head,69,1);cout<<"\nadding afterlast   "<<endl;
    // printList(head);
}
/*The insertAtFront() function takes a double pointer to the head of the linked list because we want to modify the head pointer itself, and not just the node it points to.

In C++, function arguments are passed by value by default, which means that any changes made to a function parameter will only affect the local copy of that parameter within the function. In order to modify the original pointer to the head of the linked list, we need to pass a pointer to that pointer, which is why we use a double pointer.

Here's how it works: When we pass the address of the head pointer to the insertAtFront() function as a double pointer, the function receives a copy of that address in a pointer variable. However, since it is a pointer to a pointer, the function can use it to access and modify the original pointer to the head of the linked list.

If we were to use a single pointer instead of a double pointer, the insertAtFront() function would only be able to modify the local copy of the pointer to the head of the linked list, and the changes would not be reflected in the original pointer.*/

/*After this line of code is executed, the newNode pointer now points to a newly allocated Node object on the heap, which can be used to store data and link to other nodes in a linked list.
 Node* head=new Node();*/

//  Allocating objects on the heap using dynamic memory allocation can be beneficial in some cases because it allows us to create objects with lifetimes that are not tied to the scope of the function where they were created.