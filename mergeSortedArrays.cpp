#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeVectors(const vector<int>& myVector, const vector<int>& alicesVector)
{
    // combine the sorted vectors into one large sorted vector
    vector<int> output;
    int i = 0, j = 0;
    int size1 = myVector.size();
    int size2 = alicesVector.size();
    //cout << size1;
    while(i < size1 && j < size2) {
        if(myVector[i] < alicesVector[j]){
            output.push_back(myVector[i]);
            i++;
        }
        else if(myVector[i] >= alicesVector[j]) {
            output.push_back(alicesVector[j]);
            j++;
        }
    }
    if(i == size1) {
        for(j; j < size2; j++) {
            output.push_back(alicesVector[j]);
        }
    }
    else if(j == size2) {
        for(i; i < size1; i++) {
            output.push_back(myVector[i]);
        }
    }
    return output;
}
int main() {
const vector<int> myVector {3, 4, 6, 10, 11, 15};
const vector<int> alicesVector {1, 5, 8, 12, 14, 19};

vector<int> mergedVector = mergeVectors(myVector, alicesVector);

cout << "[";
for (int i = 0; i < mergedVector.size(); ++i) {
    if (i > 0) {
        cout << ", ";
    }
    cout << mergedVector[i];
}
cout << "]" << endl;
}