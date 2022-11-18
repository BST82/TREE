#include<bits/stdc++.h>
using namespace std;

class SOlve{
    public:
      int heapHeight(int n, int a[]){
        return floor(log2(n));
      }

      int heapHeight_2nd_methd(int x,int b[]){
        int m=1,k=-1;
        while(m<x+1){
            k++;
            m*=2;
        }
        return k;
      }
};
int main(){
    cout<<"Enter no of test cases : ";
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
      SOlve obj1,obj2;
      cout<<"Height of Heap method 1 : "<<obj1.heapHeight(N, A)<<endl;
      cout<<"Height of Heap method 1 : "<<obj2.heapHeight_2nd_methd(N, A)<<endl;
    }
}