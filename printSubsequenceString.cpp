#include <iostream>
using namespace std;
void subseq(string input, string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    subseq(input.substr(1), output);
    subseq(input.substr(1), output + input[0]);
}

int main(){
    string input;
    cout<<"Enter the string:"<<endl;
    cin>>input;
    string output = "";
    subseq(input,output);
    return 0;
}