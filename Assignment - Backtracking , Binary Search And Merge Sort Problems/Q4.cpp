#include<iostream>
using namespace std;

bool check(int board[][9],int row,int col,int val)
{
    for(int k=0;k<9;k++)
    {
        if(board[row][k]==val)
            return false;
        if(board[k][col]==val)
            return false;
    }
    int TopRowIndice=row-row%3;
    int TopColIndice=col-col%3;
    for(int c=TopRowIndice;c<TopRowIndice+3;c++)
    {
    for(int d=TopColIndice;d<TopColIndice+3;d++)
    {
    if(board[c][d]==val)
    {
    return false;
    }
    }
    }
    return true;
}
bool helper(int board[][9],int row,int col)
{
    if(row==9)
    {
        return true;
    }
    if(col==9)
    return helper(board,row+1,0);
    if(board[row][col]!=0)
    {
    return helper(board,row,col+1);
    }
    for(int k=1;k<=9;k++)
    {
    if(check(board,row,col,k))
    {
    board[row][col]=k;
    if(helper(board,row,col+1))
    return true;
  }
    board[row][col]=0;
    }
    return false;
}
bool sudokuSolver(int board[][9])
{ /* Don't write main(). * Don't read input, it is passed as function argument. * Don't print output and return output as specified in the question */ return helper(board,0,0); }bool check(int board[][9],int row,int col,int val) { for(int k=0;k<9;k++) { if(board[row][k]==val) return false; if(board[k][col]==val) return false; } int TopRowIndice=row-row%3; int TopColIndice=col-col%3; for(int c=TopRowIndice;c<TopRowIndice+3;c++) { for(int d=TopColIndice;d<TopColIndice+3;d++) { if(board[c][d]==val) { return false; } } } return true; } bool helper(int board[][9],int row,int col) { if(row==9) { return true; } if(col==9) return helper(board,row+1,0); if(board[row][col]!=0) { return helper(board,row,col+1); } for(int k=1;k<=9;k++) { if(check(board,row,col,k)) { board[row][col]=k; if(helper(board,row,col+1)) return true; } board[row][col]=0; } return false; } bool sudokuSolver(int board[][9]){ /* Don't write main(). * Don't read input, it is passed as function argument. * Don't print output and return output as specified in the question */ return helper(board,0,0); }bool check(int board[][9],int row,int col,int val) { for(int k=0;k<9;k++) { if(board[row][k]==val) return false; if(board[k][col]==val) return false; } int TopRowIndice=row-row%3; int TopColIndice=col-col%3; for(int c=TopRowIndice;c<TopRowIndice+3;c++) { for(int d=TopColIndice;d<TopColIndice+3;d++) { if(board[c][d]==val) { return false; } } } return true; } bool helper(int board[][9],int row,int col) { if(row==9) { return true; } if(col==9) return helper(board,row+1,0); if(board[row][col]!=0) { return helper(board,row,col+1); } for(int k=1;k<=9;k++) { if(check(board,row,col,k)) { board[row][col]=k; if(helper(board,row,col+1)) return true; } board[row][col]=0; } return false; } bool sudokuSolver(int board[][9]){ /* Don't write main(). * Don't read input, it is passed as function argument. * Don't print output and return output as specified in the question */
    return helper(board,0,0);
}



int main(){

  int n = 9;
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }
  }
  if(sudokuSolver(board)){
	cout << "true";
  }else{
	cout << "false";
  }
}


