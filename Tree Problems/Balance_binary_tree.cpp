#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left ,*right;
};
Node* newNode(int val){
    Node* temp = new Node;
    temp->data=val;
    temp->left=temp->right=NULL;

    return temp;
}

bool balancedBT(Node* root){
 if(root==NULL) return 0;
 int l=balancedBT(root->left);
 if(l==-1) return -1;

 int r=balancedBT(root->right);
 if(r==-1) return -1;

if(abs(l-r)>1) return -1;
 return max(l,r)+1;
}
bool balanced(Node* root){
    return balancedBT(root)!=-1;
}
int main(){
Node* root= newNode(6);
root->left=newNode(2);
root->left->left=newNode(10);
root->left->left->left=newNode(10);
root->left->left->left->left=newNode(10);

cout<<balancedBT(root);
}