#include <iostream>
#include <vector>

using namespace std;

int main() {
   vector<int> v;
   cout<<v.capacity();
   /* Insert 5 elements */
   for (int i = 0; i < 5; ++i)
   {
      int a;
      cin >> a;
      v.push_back(a);
   }
   
      

   for (int i = 0; i < v.size(); ++i)
      cout << v[i] << endl;

   return 0;
}