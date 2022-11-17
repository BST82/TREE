#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node *left, *right;
};

Node* newNoed(int data){
    Node* temp=new Node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

bool univalued_Binart_Tree(Node* root){

    return (!root->left || root->left->data == root->data && univalued_Binart_Tree(root->left)) &&(!root->right ||root->right->data == root->data && univalued_Binart_Tree(root->right));
}
int main(){

 Node* root=newNoed(1);
 root->left=newNoed(1);
 root->right=newNoed(1);
 root->left->left=newNoed(1);
 root->right->right=newNoed(8);

 cout<<univalued_Binart_Tree(root);
}