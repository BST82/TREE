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

int isSameTree(Node* p, Node* q){
  if(p==NULL && q==NULL) return true;
         if(p==NULL || q==NULL) return false;
        if(p->data!=q->data) return false;
        
        
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);   
}

int main(){
struct Node* p=newNode(5);
p->left=newNode(3);
p->right=newNode(7);
p->left->right=newNode(9);
p->left->right->left=newNode(6);
p->right->left=newNode(4);
p->right->right=newNode(2);

struct Node* q=newNode(5);
q->left=newNode(3);
q->right=newNode(7);
q->left->right=newNode(9);
q->left->right->left=newNode(6);
q->right->left=newNode(4);
q->right->right=newNode(2);

cout<<isSameTree(p,q);
}

