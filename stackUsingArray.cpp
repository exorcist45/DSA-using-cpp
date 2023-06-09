#include<iostream>
#include <climits>
using namespace std;

template <typename T>
class StackUsingArray {
    T * data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray() {
        data = new T(4);
        nextIndex = 0;
        capacity = 4;
    }

    // return the number of elements in stack
    int size() {
        return nextIndex;
    }

    bool isEmpty() { 
        return nextIndex == 0;
    }

    //insert element
    void push(T element) { 
        if(nextIndex == capacity){
            /*
            cout<<"Stack Full"<<endl;
            return;
            */
            //dynamic
            T *newdata = new T[2*capacity];
            for(int i = 0; i < capacity; i++){
                newdata[i] = data[i];
            } 
            capacity *= 2;
            delete []data;
            data = newdata;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    //delete element
    T pop() {
        if(isEmpty()){
            cout<<"Stack Empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top() {
        if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return 0;        
        }
        return data[nextIndex-1];
    }
};
int main()
{
    StackUsingArray <char>s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}