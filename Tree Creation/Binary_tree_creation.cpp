#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;
    // macking constructor for data
    node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

// function for tree building

node *builtTree(node *root)
{
    cout << "Enter data " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for left " << endl;
    root->left = builtTree(root->left);

    cout << "enter data for right " << endl;
    root->right = builtTree(root->right);

    return root;
}

// void levelOrder_Traversal(node* root){

//    queue<node*>Q;
//    // adding root value in the queue
//    Q.push(root);

//    //Traverse Queue untill empty

//    while(!Q.empty()){
//     // temp will contain front of queue
//     node* temp = Q.front();
//     cout<<temp->data<<" ";
//     Q.pop();

//     // cheching left value in tree
//     // temp->left === left value of temp is NON NULL
//     if(temp->left){
//      Q.push(temp->left);
//     }

//     // for right value of temp
//     if(temp->right){
//      Q.push(temp->right);
//     }
//    }

// }

void levelOrder_Traversal(node *root)
{

    queue<node *> Q;
    // adding root value in the queue
    Q.push(root);
    // for printing in levelorder
    Q.push(NULL); // Act as seprator
    // Traverse Queue untill empty

    while (!Q.empty())
    {
        // temp will contain front of queue
        node *temp = Q.front();

        Q.pop();

        // for new line we will use seprator
        if (temp == NULL)
        {
            // temp==NULL , previous level traverse till all element so need to switch on new line
            cout << endl;
            if (!Q.empty())
            {
                // Again check Q is not empty then child is there so push NULL in Queue
                Q.push(NULL); // act as another seprator
            }
        }
        else
        {
            cout << temp->data << " ";
            // cheching left value in tree
            // temp->left === left value of temp is NON NULL
            if (temp->left)
            {
                Q.push(temp->left);
            }

            // for right value of temp
            if (temp->right)
            {
                Q.push(temp->right);
            }
        }
    }
}

void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void builtfrom_Level_Order(node *&root)
{
    // level order == Queue
    queue<node *> qUe;
    cout << "enter data for root " << endl;
    int data;
    cin >> data;
    root = new node(data); // passing input data
    qUe.push(root);

    while (!qUe.empty())
    {
        node *temp = qUe.front();
        qUe.pop();

        cout << "Enter left node for " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            qUe.push(temp->left);
        }

        cout << "Enter right node for " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            qUe.push(temp->right);
        }
    }
}
int main()
{

    node *root = NULL;

    // // creating a tree
    // root = builtTree(root);

    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 -1
    // cout << "Level order traversal " << endl;
    // levelOrder_Traversal(root);

    // cout<<endl;
    // inOrder(root);

    // cout<<endl;
    // preOrder(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1
    builtfrom_Level_Order(root);
    levelOrder_Traversal(root);
}