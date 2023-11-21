#include<iostream>
#include<cmath>
using namespace std;
class nqueens{
  public:
  void Q(int boardsize);
  bool place(int board[],int row,int col);
  void display(int board[],int boardsize);
  void Queen(int board[],int col,int boardsize);
};

void nqueens::Q(int boardsize){
  int *board = new int[boardsize];
  for(int i=0;i<boardsize;i++){
    board[i]=0;
  }
  Queen(board,0,boardsize);
  delete[]board;
}
bool nqueens::place(int board[],int row,int col){
  for(int i=0;i<col;i++){
    if(board[i] == row ||abs(board[i]-row)==abs(i-col)){
      return false;
    }
    
  }
  return true;
}
void nqueens::display(int board[],int boardsize){
  cout<<"\n---------------------------------------------\n";
  for(int i=0;i<boardsize;i++){
    for(int j=0;j<boardsize;j++){
      cout<<"  "<<(board[j] == i ? 1:0);
    }
    cout<<"\n";
  }
}
void nqueens::Queen(int board[],int col,int boardsize){
  if(col == boardsize){
    display(board,boardsize);
    return;
  }
  
  for(int i=0;i<boardsize;i++){
    if(place(board,i,col)){
      board[col]=i;
      Queen(board,col+1,boardsize);
    }
  }
}
int main(){
  int n;
  cout<<"\nEnter the number of queens to be placed\n";
  cin>>n;
  nqueens nq;
  nq.Q(n);
  return 0;
}
