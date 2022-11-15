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

void levelOrder(struct Node* root){
  struct Node* temp;
  queue<Node*>Q;
  if(!root) return ;
  Q.push(root);

  while(!Q.empty()){
    temp=Q.front();
    cout<<temp->data<<" ";

    if(temp->left!=NULL){
      Q.push(temp->left);
    }
    if(temp->right){
        Q.push(temp->right);
    }
    
    Q.pop();
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

cout<<"Pre oreder Traversal : "; levelOrder(root);
}
// TC : O(N);
//SC : O(N);