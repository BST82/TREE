#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};


Node* newNode(int data){
Node* temp=new Node;
temp->data=data;
temp->left=temp->right=NULL;
return temp;
}
// inorder traversal 

void inOrder(struct Node* root){
if(root){
inOrder(root->left);
cout<<root->data<<" ";
inOrder(root->right);
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
  cout << "Inorder traversal of binary tree is : ";
    inOrder(root);

}
// TC :O(N)
// SC : not using stack SC: O(1);
// SC : otherwise O(h);