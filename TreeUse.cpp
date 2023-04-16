#include<iostream>
#include "TreeNode.h"
using namespace std;

void print(TreeNode<int>* root){
    cout<<root->data<<":";
    for(int i =0; i < root -> children.size(); i++) {
        cout<< root -> children[i]->data<<",";
    }
    cout << endl;
    for(int i =0; i < root -> children.size(); i++) {
        print(root -> children[i]);
    }
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);
    root -> children.push_back(move(node1));
    root -> children.push_back(move(node2));
    print(root);
    
    return 0;
}