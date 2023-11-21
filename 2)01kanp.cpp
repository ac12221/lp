#include<iostream>
using namespace std;

void selecteditem(int A[][100],int w[],int n,int kc){
  int i=n,j=kc;
  while(i>0 && j>0){
    if(A[i][j]!=A[i-1][j]){
      cout<<"Item"<<i<<" is included "<<endl;
      j-=w[i-1];
    }
    i--;
  }
}

int ks(int kc,int p[],int w[],int n){
  int i,j;
  int A[n+1][100];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=kc;j++){
      if(i==0  || j==0){
        A[i][j]=0;
      }
      else if(w[i-1]<=j){
        A[i][j]=max(A[i-1][j],A[i-1][j-w[i-1]]+p[i-1]);
      }
      else{
        A[i][j] = A[i-1][j];
      }
    }
  }
  cout<<"Matrix for knapsack is :"<<endl;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=kc;j++){
      cout<<" "<<A[i][j];
    }
    cout<<"\n";
  }
  cout<<"\n";
  
  cout<<"Max profit for kanpsack is :"<<A[n][kc]<<endl;
  selecteditem(A,w,n,kc);
  return 0;
}
int main(){
  int i,n,kc;
  cout<<"\nEnter the capacity of knapsack";
  cin>>kc;
  cout<<"\nEnter the number of items available:";
  cin>>n;
  
  int p[n],w[n];
  for(int i=0;i<n;i++){
    cout<<"Enter the profit and weight for the item "<<i+1<<":"<<endl;
    cin>>p[i]>>w[i];
  }
  ks(kc,p,w,n);
  return 0;
    
}
