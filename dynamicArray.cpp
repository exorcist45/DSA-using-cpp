#include<iostream>
using namespace std;
class DynamicArray {
    int *data;
    int nextIndex;
    int capacity;

    public:
    DynamicArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    DynamicArray(DynamicArray const &d){
        //this -> data = d.data; // Shallow copy

        //Deep Copy
        this -> data = new int[d.capacity];
        for(int i = 0; i < d.nextIndex;i++){
            this -> data[i] = d.data[i];
        }
        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }

    void operator=(DynamicArray const&d) {
         this -> data = new int[d.capacity];
        for(int i = 0; i < d.nextIndex;i++){
            this -> data[i] = d.data[i];
        }
        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }

    void add(int element){
        if(nextIndex == capacity){
            int *newdata = new int[2 * capacity];
            for(int i = 0; i < capacity; i++){
                newdata[i] = data[i];
            }
            delete [] data;
            data = newdata;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    void add(int i, int element) {
        if(i < nextIndex){
            data[i] = element;
        }
        else if(i == nextIndex) {
            add(element);
        }
        else{
            return;
        }
    }
    int get(int i) const {
        if(i < nextIndex){
           return data[i]; 
        }
        else {
            return -1;
        }
    }

    void print() const{
        for(int i = 0; i < nextIndex; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    
};

int main()
{
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.print();
    DynamicArray d2(d1);
    d2.add(1,40);
    d1.print();
    d2.print();
    DynamicArray d3 = d2;
    d3.add(2,40);
    d2.print();
    d3.print();
    return 0;
}