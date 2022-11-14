#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

//using recursion 
void preOrder(struct Node* root){
if(root){
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
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

cout<<"Pre oreder Traversal : "; preOrder(root);

}
//TC : O(N);
//SC:Don’t consider the size of the stack for function calls then O(1) otherwise O(h) where h is the height of the tree. 