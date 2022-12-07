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

void path(vector<string>&ans, Node* root, string s){

}

vector<string>binaryTreePaths(Node* root){
 vector<string>answewr;
 if(!root) return answewr;

 path(answewr,root,to_string(root->data));
 return answewr;
}
int main(){
     Node* root= newNode(1);
     root->left=newNode(2);
     root->right=newNode(3);
     root->left->right=newNode(5);
}