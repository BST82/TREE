#include<bits/stdc++.h>
using namespace std;

struct Node{
 int data;
 Node *left, *right;
};

Node* newNode(int val){
  Node* temp= new Node();
  temp->data=val;
  temp->left=temp->right=NULL;

  return temp;
}