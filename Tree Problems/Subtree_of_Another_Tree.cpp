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

 bool symmetric(Node* root, Node* subRoot){
       
        if((root==NULL && subRoot!=NULL) || (root!=NULL && subRoot==NULL)) return false;
        if(root==NULL && subRoot==NULL) return true;
        if(root->data!=subRoot->data) return false;
        
        return symmetric(root->left,subRoot->left) && symmetric(root->right,subRoot->right);
        
     
        
    }
    bool isSubtree(Node* root, Node* subRoot) {
        if(root==NULL) return false;
        if(root->data==subRoot->data){
            bool res=symmetric(root,subRoot);
            if(res) return true;
        }
        bool l=isSubtree(root->left,subRoot);
        bool r=isSubtree(root->right,subRoot);
        
        return l||r;
      
    }

int main(){
struct Node* p=newNode(5);
p->left=newNode(3);
p->right=newNode(7);
p->left->left=newNode(1);
p->left->right=newNode(2);


struct Node* q=newNode(3);
q->left=newNode(1);
q->right=newNode(2);


cout<<isSubtree(p,q);
}

