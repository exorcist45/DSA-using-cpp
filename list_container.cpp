#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std; 
void display(list <int> l) 
{ 
    list <int> :: iterator i; 
    for(i = l.begin(); i != l.end(); ++i) 
        cout << '\t' << *i; 
    cout << '\n'; 
} 
int main() 
{ 

    list <int> lst1, lst2; 
    lst1.insert(lst1.begin(),15);
    lst1.push_front(20);
    lst1.push_back(18);
    lst1.insert(lst1.begin(),40);
    cout <<"\nList 1:\n"; 
    display(lst1); 
    cout << "\nUsing list.front() function:\n " << lst1.front(); 
    cout << "\nUsing list.back() function:\n " << lst1.back();
    cout << "\nUsing list.pop_back() function:\n "; 
    lst1.pop_back(); 
    display(lst1); 
    cout << "\nUsing list.pop_front() function:\n "; 
    lst1.pop_front(); 
    display(lst1); 
    lst1.insert(lst1.end(),18);
    cout << "\nThe list.reverse() function:\n "; 
    lst1.reverse(); 
    display(lst1); 
    cout << "\nThe list.sort() function:\n"; 
    lst1.sort(); 
    display(lst1); 
    
    return 0; 
} 
