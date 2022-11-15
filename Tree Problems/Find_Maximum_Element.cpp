#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left , *right;
};
Node* newNode(int data){
  Node* temp= new Node;
  temp->data=data;
  temp->left=temp->right=NULL;
  return temp;
}

int findMax(struct Node* root){
 int root_data,left,right,max=INT_MIN;
  if(root!=NULL){
    root_data=root->data;
    left=findMax(root->left);
    right=findMax(root->right);

    if(left>right){
        max=left;
    }else{
        max=right;
    }

    if(root->data>max){
        max=root_data;
    }
  }

  return max;
}

int main(){
struct Node* root=newNode(5);
root->left=newNode(3);
root->right=newNode(7);
root->left->right=newNode(9);
root->left->right->left=newNode(6);
root->right->left=newNode(4);
root->right->right=newNode(2);

cout<<"Maximum element is : "<<findMax(root);
}

// find maximum element in binary tree using recursion 
// TC: O(N);
//SC:O(N);