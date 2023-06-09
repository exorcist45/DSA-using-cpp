#include <iostream>
using namespace std;

void psubset(int input[],int size,int k,int output[],int m)
{
    if(size==0)
    {
        if(k==0)
        {
            for(int i=0;i<m;i++)
            {
                cout<<output[i]<<" ";
            }
            cout<<endl;
            return;
        }
        else
            return;
    }
    
    int o1[m+1];
    int i;
    for(i=0;i<m;i++)
    {
        o1[i]=output[i];
    }
    o1[i]=input[0];
    psubset(input+1,size-1,k-input[0],o1,m+1);
    psubset(input+1,size-1,k,output,m);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int m=0;
    int output[m];
    psubset(input,size,k,output,m);
}

int main(){
    int input[1000],length,k;
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];
    cin>>k;
    printSubsetSumToK(input, length,k);
    return 0;
}