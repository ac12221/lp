#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
#define MAX_N 10

int N;
int M[MAX_N][MAX_N];
int cost = INT_MAX;
int best_path[MAX_N];

void tsp_branch_and_bound(int path[MAX_N],bool visited[MAX_N],int bound,int level){
  if(level== N){
    int current_cost = bound + M[path[N-1]][path[0]];
    if(current_cost<cost){
      cost = current_cost;
      copy(path,path+N,best_path);
    }
    return;
  }
  for(int i=0;i<N;i++){
    if(!visited[i]){
      int new_bound = bound + M[path[level-1]][i];
      if(new_bound<cost){
        path[level]=i;
        visited[i]=true;
        tsp_branch_and_bound(path,visited,new_bound,level+1);
        visited[i]=false;
      }
    }
  }
}

int main(){
  cout<<"Enter the size of distance matrix (max "<<MAX_N<<")";
  cin>>N;
  if(N>MAX_N){
    cout<<"Invalid entry"<<endl;
    return 1;
  }
  
  cout<<"Enter the distance matrix"<<N<<"x"<<N<<endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>M[i][j];
    }
  }
  int path[MAX_N];
  bool visited[MAX_N]={false};
  path[0]=0;
  visited[0]=true;
  tsp_branch_and_bound(path,visited,0,1);
  cout<<"Minimum cost is : "<<cost<<endl;
  cout<<"Best path is : ";
  for(int i=0;i<N;i++){
    cout<<best_path[i]<<"-->";
  }
  cout<<best_path[0]<<endl;
  return 0;
}
