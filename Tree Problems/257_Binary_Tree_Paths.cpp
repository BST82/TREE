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
     
     if(!root->left && !root->right){
        ans.push_back(s);
        return ;
     }
     if(root->left){
        path(ans,root->left,s + "->"+ to_string(root->left->data));
     }

     if(root->right){
        path(ans,root->right,s +"->"+ to_string(root->right->data));
     }
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

     vector<string>s=binaryTreePaths(root);
     for(auto &i:s){
        cout<<i<<endl;
     }
     
}