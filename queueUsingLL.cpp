#include<iostream>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Queue {
    Node<T> *head;
    Node<T> *tail;
    int size;

    public:
    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getsize() {
        return size; 
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(T element) {
        Node<T> *newNode = new Node<T>(element);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        size++;
    }

    T front() {
        if(isEmpty()){
            cout<<"Queue is empty!" << endl;
            return -1;
        }
        return head -> data;
    }

    T dequeue() {
        if(isEmpty()){
            cout<<"Queue is empty!" << endl;
            return -1;
        }
        T ans = head -> data;
        Node<T>* temp = head;
        head = head -> next;
        delete temp;
        size--;
        return ans;
    }
};
int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}