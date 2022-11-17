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

bool sys(Node* root){
    return (root==NULL) || symmetric_Tree(root->left,root->right);
}
int main(){
struct Node* L=newNode(5);
L->left=newNode(3);
L->right=newNode(7);
L->left->right=newNode(9);
L->left->right->left=newNode(6);
L->right->left=newNode(4);
L->right->right=newNode(2);

struct Node* R=newNode(5);
R->left=newNode(3);
R->right=newNode(7);
R->left->right=newNode(9);
R->left->right->left=newNode(6);
R->right->left=newNode(4);
R->right->right=newNode(2);
cout<<symmetric_Tree(L,R);
}

