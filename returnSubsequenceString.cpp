#include <iostream>
using namespace std;

int subsequence(string input, string output[]){
    if(input.empty()){
        output[0] == "";
        return 1;
    }
    string smallString = input.substr(1);
    int smallOutputSize = subsequence(smallString,output);
    for (int i = 0; i  < smallOutputSize; i++){
        output[i + smallOutputSize] = input[0]  + output[i];
    }
    return 2 * smallOutputSize;
}

int main(){
    string input;
    cout<< "Enter the string: "<<endl;
    getline(cin,input);
    string output[1000];
    int range = subsequence(input,output);
    for (int i = 0; i < range; i++){
        cout<<output[i]<<endl;
    }
    return 0;
}