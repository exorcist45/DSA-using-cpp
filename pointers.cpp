#include <iostream>
using namespace std;
int main(){
    int a = 10;
    int* p1 = &a;
    int ** p2 = & p1;
    cout<<p2<<endl;
    cout<<*p1<<endl;
    int b = (*p1)++;
    cout<<b<<endl;
    cout<< a << endl;
    cout<< (*p2)++<<endl;

    return 0;
}