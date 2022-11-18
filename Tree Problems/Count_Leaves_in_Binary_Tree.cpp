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

if(s.length()==0 || s[0]=='N') return NULL;
vector<string>s1;
istringstream iss(s);
for(string s; iss>>s;) {s1.push_back(s);}

Node* root=newNode(stoi(s1[0]));

queue<Node*>Q;
Q.push(root);

int i=1;
while(!Q.empty() && i<s1.size()){
    Node* currNode=Q.front();
    Q.pop();
    string s2=s1[i];
    if(s2!="N"){
        currNode->left=newNode(stoi(s2));
        Q.push(currNode->left);
    }
    //for right chile
    i++;
    if(i>=s1.size()) break;
    s2=s1[i];
    if(s2!="N"){
        currNode->right=newNode(stoi(s2));
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