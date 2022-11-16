#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};
 Node* newNode(int data){
    Node* temp=new Node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

int findMIN(Node* root){
    int root_data,left,right,mini=INT_MAX;

   if(root!=NULL){
    root_data=root->data;
    left=findMIN(root->left);
    right=findMIN(root->right);
   

   if(left>right){
     mini=right;
   }else{
    mini=left;
   }

if(root->data<mini){
    mini=root_data;
}
}
return mini;
}

int main(){
struct Node* root=newNode(5);
root->left=newNode(3);
root->right=newNode(7);
root->left->right=newNode(9);
root->left->right->left=newNode(6);
root->right->left=newNode(4);
root->right->right=newNode(2);

cout<<"Maximum element is : "<<findMIN(root);
}



// find minimum element in binary tree using recursion 
// TC: O(N);
//SC:O(N);