#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

Node * newNode(int data){
    Node* temp= new Node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

Node* treeInput(string s){

if(s.length()==0 || s[0]=='N') return NULL; //base case;

// creating vector of string from input
vector<string>s1;
// string after spiting by space
istringstream iss(s);
for(string s; iss>>s;) {s1.push_back(s);}

//creating root of the tree
Node* root=newNode(stoi(s1[0]));

//push the root to queue
queue<Node*>Q;
Q.push(root);

// staring from the second element 
int i=1;
while(!Q.empty() && i<s1.size()){
    // get front of queue
    Node* currNode=Q.front();
    // remove front of queue
    Q.pop();
    //get the current node's value from the string
    string s2=s1[i];
    //if left child is not null
    if(s2!="N"){
        //create left child for the current node
        currNode->left=newNode(stoi(s2));
        //push currNode->left to queue;
        Q.push(currNode->left);
    }
    //for right chile
    i++;
    if(i>=s1.size()) break;
    s2=s1[i];
    //if right child is not NULL
    if(s2!="N"){
        // creating right child for current node
        currNode->right=newNode(stoi(s2));
        //push to the queue
        Q.push(currNode->right);
    }
    i++;
}
return root;
}
int countLeaves(Node* root)
{
  // Your code here
  int count=0;
  if(root==NULL) {return 0;}
  if((root->left==NULL) && (root->right==NULL)) {count+=1;}
  else{
      return countLeaves(root->left)+countLeaves(root->right);
  }
 return count;
}
int main(){
    cout<<"Enter wlements of tree : ";
    int t;
    cin>>t;
    while(t--){
        string s;
        getline(cin,s);
        Node* root =treeInput(s);
        cout<<"Total count of leaves in Binary Tree : "<<countLeaves(root)<<endl;
    }
}