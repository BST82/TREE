#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer
to left child and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
 
/* Helper function that allocates a new node with
the given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
/* Change a tree so that the roles of the left and
    right pointers are swapped at every node.
 
So the tree...
     4
    / \
   2   5
  / \
 3   1
 
is changed to...
     4
    / \
   5   2
      / \
     1   3
*/
void mirror(struct Node* node)
{
    if (node == NULL)
        return;
    else {
        struct Node* temp;
 
        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);
 
        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
 
/* Helper function to print
Inorder traversal.*/
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
// Driver Code
int main()
{
    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);
 
    /* Print inorder traversal of the input tree */
    cout << "Inorder traversal of the constructed"
         << " tree is" << endl;
    levelorder(root);
 
    /* Convert tree to its mirror */
    mirror(root);
 
    /* Print inorder traversal of the mirror tree */
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";
    levelorder(root);
 
    return 0;
}