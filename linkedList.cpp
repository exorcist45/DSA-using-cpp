#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        next = NULL;
    }

};

Node* takeInput() {
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1) {
        Node *newnode = new Node(data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail -> next = newnode;
            tail = tail -> next;
            // OR
            // tail = newnode;
        }
        cin>>data;
    }
    return head;  
}

Node* insertNode(Node *head, int i, int data) {
    Node *newnode = new Node(data);
    int count = 0;
    Node *temp = head;
    if(i == 0){
        newnode -> next = head;
        head = newnode;
        return head;
    }
    while(temp != NULL && count < i - 1){
        temp = temp -> next;
        count++;
    }
    if(temp !=NULL){
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
    return head;
}

void print(Node *head){
    Node *temp = head;
    while(temp != NULL ) {
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
}
int main()
{

    Node *head = takeInput();
    print(head);
    int i,data;
    cout<< "Enter position and data"<<endl;
    cin>>i>>data;
    head = insertNode(head, i, data);
    print(head);
    /*
    //Static
    Node n1(1);
    Node* head = &n1;

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    print(head);
    */
    /*
    n1.next = &n2;

    cout<< head -> data << endl;

    //Dynamically
    Node *n3 = new Node(10);
    Node *head = n3;
    Node *n4 = new Node(20);
    n3 -> next = n4;
    */
    return 0;
}