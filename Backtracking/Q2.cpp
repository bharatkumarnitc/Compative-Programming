#include<bits/stdc++.h>
using namespace std;
void print(int **arr,int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
}
void helper(int maze[][20],int **arr,int n,int x,int y)
{

    if(x==n-1 && y==n-1)
    {
        arr[x][y]=1;
        print(arr,n);
        arr[x][y]=0;
        return;
    }

    if(x>=n ||x<0|| y>=n ||y<0 || maze[x][y]==0 || arr[x][y]==1)
        return;
    arr[x][y]=1;
    helper(maze,arr,n,x-1,y);
    helper(maze,arr,n,x+1,y);
    helper(maze,arr,n,x,y-1);
    helper(maze,arr,n,x,y+1);
    arr[x][y]=0;

}



void ratInAMaze(int maze[][20], int n)
{

   int** solution = new int*[n];
  for(int i=0;i<n;i++)
  {
  	solution[i] = new int[n];
  }

        helper(maze,solution,n,0,0);
}


int main(){

  int n;
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }
  }
  ratInAMaze(maze, n);
}



