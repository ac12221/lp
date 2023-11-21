#include<iostream>
#include<climits>
using namespace std;
struct Edge{
  int source,destination,weight;
};
struct Graph{
  int V, E;
  struct Edge* edge;
};
struct Graph* createGraph(int V,int E){
  struct Graph* graph =new Graph;
  graph->V=V;
  graph->E=E;
  graph->edge = new Edge[E];
  return graph;
}
void BellmanFord(struct Graph* graph,int source){
  int V = graph-> V;
  int E = graph-> E;
  int dist[V];
  for(int i=0;i<V;i++){
    dist[i] = INT_MAX;
  }
  dist[source]=0;
  for(int i=0;i<=V-1;i++){
    for(int j=0;j<E;j++){
      int u = graph->edge[j].source;
      int v = graph->edge[j].destination;
      int weight = graph->edge[j].weight;
      if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
        dist[v]=dist[u]+weight;
    }
  }
  for(int i=0;i<E;i++){
    
      int u = graph->edge[i].source;
      int v = graph->edge[i].destination;
      int weight = graph->edge[i].weight;
      if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]){
        cout<<"Graph contains negative weight cycle";
        return;
      }
  }
  cout<<"\nVertex:\t\t";
  for(int i=0;i<V;i++){
    cout<<"\t"<<i;
  }
  cout<<"\nDistance from source :";
  for(int i=0;i<V;i++){
    cout<<"\t"<<dist[i];
  }
  return;
  
}
int main(){
  int V,E;
  cout<<"\nEnter the number of vertices of the graph";
  cin>>V;
  cout<<"\nEnter the number of edges in the graph";
  cin>>E;
  struct Graph*graph =createGraph(V,E);
  int start;
  cout<<"\nEnter the start edge of the graph from 0 to"<<V-1<<" :";
  cin>>start;
  for(int i=0;i<E;i++){
    int src,dest,wt;
    cout<<"Enter source destination and weight for edge "<<i+1<<" : ";
    cin>>src>>dest>>wt;
    
    graph->edge[i].source = src;
    graph->edge[i].destination = dest;
    graph->edge[i].weight = wt;
  }
  BellmanFord(graph,start);
  return 0;
}
