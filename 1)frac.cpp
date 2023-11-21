#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
struct Item{
  int profit,weight;
  Item() : profit(0),weight(0){}
  Item(int p,int w): profit(p),weight(w){}
};
bool cp(const Item& a,const Item& b){
  return a.profit>b.profit;
}
bool cw(const Item& a,const Item&b){
  return a.weight< b.weight;
}
bool cpw(const Item& a,const Item&b){
  return (double)(a.profit)/a.weight > (double)(b.profit)/b.weight;
}

double fk(Item items[],int cap,int num,function<bool(const Item& , const Item&)>comp){
  sort(items,items+num,comp);
  int nw =0;
  double tp =0.0;
  for(int i=0;i<num;i++){
    if(nw + items[i].weight <= cap){
      nw+=items[i].weight;
      tp+=items[i].profit;
    }
    else{
      int rc = cap-nw;
      tp += items[i].profit*(double)(rc)/items[i].weight;
      break;
    }
  }
  return tp;

}

int main(){
  int num,cap,p,w;
  cout<<"\nEnter the capacity of bag :";
  cin>>cap;
  cout<<"\nEnter the number of items :";
  cin>>num;
  Item items[num];
  
  for(int i=0;i<num;i++){
    cout<<"\n Enter profit and weight for item "<<i<<":";
    cin>>p>>w;
    items[i] = Item(p,w);
  }
  cout<<"MAX Profit (by max profit) is : "<<fk(items,cap,num,cp)<<endl;
  cout<<"MAX Profit (by max weight) is : "<<fk(items,cap,num,cw)<<endl;
  cout<<"MAX Profit (by max profit/weight) is : "<<fk(items,cap,num,cpw)<<endl;
  

}
