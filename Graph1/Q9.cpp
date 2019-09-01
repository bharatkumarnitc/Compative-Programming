#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
int flag=0;
void dfs(int x,int y,int a,int b,char s[][MAXN],int **vis,int n,int m)   
{
    if (vis[x][y])   
    {
        
        flag = 1;
        return;
    } 
    vis[x][y] = 1;
    if (x < n - 1 && s[x+1][y] == s[x][y] && ((x+1) != a || y != b))
	 dfs(x+1,y,x,y,s,vis,n,m);
    if (x > 0 && s[x-1][y] == s[x][y] && ((x-1) != a || y != b))
	 dfs(x-1,y,x,y,s,vis,n,m);
    if (y < m - 1 && s[x][y+1] == s[x][y] && (x != a || (y+1) != b))
	 dfs(x,y+1,x,y,s,vis,n,m);
    if (y > 0 && s[x][y-1] == s[x][y] && (x != a || (y-1) != b)) 
	dfs(x,y-1,x,y,s,vis,n,m);
}
int solve(char board[][MAXN],int n, int m)
{
    
    int **vis=new int*[n];
    for(int i=0;i<n;i++)
    {
        vis[i]=new int[m];
        for(int j=0;j<m;j++)
            vis[i][j]=0;
    }
    
    
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j]==0)
                dfs(i,j,i,j,board,vis,n,m);
        }
    }

    
    return flag;
	// Write your code here.
}
int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}
