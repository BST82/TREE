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

int summ=0;
int range(Node * root, int low,int high){
    if(!root)return 0;
    range(root->left,low,high);
    if(root->data >=low && root->data <=high){
        summ+=root->data;
    }
    range(root->right,low,high);
    return summ;
}
int sumBetweenRange(Node* root,int low,int high){
    return range(root,low,high);
}

int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(18);
 
    int low=7;
    int high=15;
 cout<<"Sum b/w range : "<<sumBetweenRange(root,low,high);
 
    return 0;
}