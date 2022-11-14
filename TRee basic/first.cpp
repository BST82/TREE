#include<bits/stdc++.h>
using namespace std;

template<typename T>

class TreeNode{
    public:
     T data;
     vector<TreeNode<T>*>childern;

     // constructor;
     TreeNode(T data){
        this->data=data;
     }

     //destructor;
     ~TreeNode(){
        for(int i=0;i<childern.size();i++){
            delete childern[i];
        }
     }
};
TreeNode<int>*takeInput(){
queue<TreeNode<int>*>pendingnodes;
cout<<"Enter root data : "<<endl;
int rootdata;
cin>>rootdata;

TreeNode<int>* root=new TreeNode<int>(rootdata);
pendingnodes.push(root);

while(pendingnodes.size()!=0){
    TreeNode<int>*currentNode=pendingnodes.front();
    pendingnodes.pop();
    cout<<"Enter number of childrens of "<<currentNode->data<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int currentchild;
        cout<<"Enter "<<i<<"th child data of "<<currentNode->data<<endl;
        cin>>currentchild;
        TreeNode<int>* childNode=new TreeNode<int>(currentchild);
        currentNode->childern.push_back(childNode);
        pendingnodes.push(childNode);
    }
}
return root;
}

void printtreeLevelWise(TreeNode<int>* root){
queue<TreeNode<int>*>temp;
temp.push(root);
while(temp.size()!=0){
    TreeNode<int>*currentNode=temp.front();
    temp.pop();
    string toBePrint=to_string(currentNode->data)+":";

    for(int i=0;i<currentNode->childern.size();i++){
        toBePrint+=to_string(currentNode->childern[i]->data)+",";
        temp.push(currentNode->childern.at(i));
    }
    if(toBePrint[toBePrint.length()-1]==','){
     toBePrint=toBePrint.substr(0,toBePrint.length()-1);
    }
    cout<<toBePrint<<endl;
}
}

void printTreeUsingRecursion(TreeNode<int>* root){
    if(root==NULL){return;}
    string toBeprint=to_string(root->data)+":";
    for(int i=0;i<root->childern.size();i++){
        toBeprint+=to_string(root->childern[i]->data)+",";
    }
     if(toBeprint[toBeprint.length()-1]==','){
     toBeprint=toBeprint.substr(0,toBeprint.length()-1);
    }
    cout<<toBeprint<<endl;
    for(int i=0;i<root->childern.size();i++){
        printTreeUsingRecursion(root->childern[i]);
    }
}
int main(){

   TreeNode<int>* root=takeInput();
//    printtreeLevelWise(root); // using iteration;
   cout<<"Using recursion "<<endl;
   printTreeUsingRecursion(root);
}