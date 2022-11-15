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

int findMax(struct Node* root)
  {
    if(root==NULL){ return -1;}

    Node* temp=root;
    Node* prevtemp;
    int maxi=INT_MIN;

    while(temp!=NULL){
        if(temp->left==NULL){
            maxi=max(maxi,temp->data);
            temp=temp->right;
        }else{
            prevtemp=temp->left;
            while(prevtemp->right!=NULL && prevtemp->right!=temp) {
                prevtemp=prevtemp->right;
            }

            if(prevtemp->right==NULL){
                prevtemp->right=temp;
                temp=temp->left;
            }else{
                prevtemp->right=NULL;
                maxi=max(maxi,temp->data);
                temp=temp->right;
            }
        }
    }
    return maxi;
  }

int main(){

struct Node* root=newNode(5);
root->left=newNode(3);
root->right=newNode(7);
root->left->right=newNode(9);
root->left->right->left=newNode(6);
root->right->left=newNode(4);
root->right->right=newNode(92);

cout<<"Maximum element is : "<<findMax(root);
}