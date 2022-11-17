#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};
 Node* newNode(int data){
    Node* temroot=new Node;
    temroot->data=data;
    temroot->left=temroot->right=NULL;
    return temroot;
}


 bool symmetric_Tree(Node* left,Node* right){
    if(left== NULL || right== NULL) return left==right;
    if(left->data!=right->data) return false;
    return symmetric_Tree(left->left,right->right) && symmetric_Tree(left->left,right->right);
 }

bool check_symmetrick(Node* root){
    return (root==NULL) || symmetric_Tree(root->left,root->right);
}
int main(){
struct Node* root=newNode(1);
root->left=newNode(2);
root->right=newNode(2);
root->left->left=newNode(3);
root->left->right=newNode(4);
root->right->left=newNode(4);
root->right->right=newNode(3);

cout<<check_symmetrick(root);
}

