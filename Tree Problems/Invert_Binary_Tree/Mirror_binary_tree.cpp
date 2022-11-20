#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
void mirror(struct Node* node)
{
    if (node == NULL)
        return;
    else {
        struct Node* temp;
 
    
        mirror(node->left);
        mirror(node->right);
 
       
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
 
void levelorder(struct Node* node)
{
      struct Node* temp;
  queue<Node*>Q;
  if(!node) return ;
  Q.push(node);

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

int main()
{
    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);
 
   
    cout << "Inorder traversal of the constructed"
         << " tree is" << endl;
    levelorder(root);
 
   
    mirror(root);
 
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";
    levelorder(root);
 
    return 0;
}