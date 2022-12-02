#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left ,*right;
};
Node* newNode(int val){
    Node* temp = new Node;
    temp->data=val;
    temp->left=temp->right=NULL;

    return temp;
}
  int sumpre(Node* root,int sum){
        if(root==NULL)return 0;
         sum=(2*sum)+root->data;
        if(root->left==NULL && root->right== NULL)return sum;
       
        return sumpre(root->left,sum)+sumpre(root->right,sum);
    }

int sumRootToLeaf(Node* root) {
        return sumpre(root,0);
    }
  
int main(){
Node* root= newNode(1);
root->left=newNode(0);
root->right=newNode(1);
root->left->left=newNode(0);
root->left->left->right=newNode(1);
root->right->left=newNode(0);
root->right->right=newNode(1);
cout<<"Sum is : "<<sumRootToLeaf(root);
}