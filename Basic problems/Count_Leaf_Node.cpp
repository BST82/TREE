#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};
node *newNode(int data)
{
    node *temp = new node(data);
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return (temp);
}
void count_Using_postOrder(node *root, int &count)
{

    if (root == NULL)
        return;
    count_Using_postOrder(root->left, count);
    count_Using_postOrder(root->right, count);
    if (root->left == NULL and root->right == NULL)
    {
        count++;
    }
    
}

int postOrder(node* root){
    int count = 0;
    count_Using_postOrder(root, count);
    return count;
}

int main()
{

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"Count of child node : "<<postOrder(root);
}