#include<bits/stdc++.h>
using namespace std;

struct Node{
 int data;
 struct Node *left,*right;
};

Node* newNode(int data){
Node* temp=new Node;
temp->data=data;
temp->left=temp->right=NULL;
return temp;
}

void postOrder(struct Node* root){
    if(root){
     postOrder(root->left);
     postOrder(root->right);
     cout<<(root->data)<<" ";
    }
}
int main(){
struct Node* root=newNode(5);
root->left=newNode(3);
root->right=newNode(7);
root->left->right=newNode(9);
root->left->right->left=newNode(6);
root->right->left=newNode(4);
root->right->right=newNode(2);
  cout << "Post order traversal of binary tree is : ";
    postOrder(root);
}