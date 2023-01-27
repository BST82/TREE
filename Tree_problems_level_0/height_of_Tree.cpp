#include <bits/stdc++.h>
using namespace std;
 
class node {
public:
    int data;
    node* left;
    node* right;
};
 
int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
   
        int left = maxDepth(node->left);
        int right = maxDepth(node->right);
        
        int ans=max(left,right);
        return ans+1;
}
 
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}
 
// Driver code
int main()
{
    node* root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout <<maxDepth(root);
    return 0;
}