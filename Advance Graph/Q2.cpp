#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define N 1000000007

bool matrix[1001][1001], visited[1001][1001];
long long fact[1000000], count;

void factorial()
{
    fact[0] = fact[1] = 1;

    for (int i = 2; i < 1000000; i++)
        fact[i] = (i * (fact[i - 1]) % N + N ) % N;
}

bool dfs(int x, int y, int row, int column)
{
    if (x < 0 || y < 0 || x >= row || y >= column)
        return 0;

    if (visited [x][y])
        return 0;

    if (!matrix [x][y])
        return 0;

    visited [x][y] = true;

    count = (count + dfs (x + 2, y - 1, row, column)) % N;
    count = (count + dfs (x + 2, y + 1, row, column)) % N;
    count = (count + dfs (x + 1, y - 2, row, column)) % N;
    count = (count + dfs (x - 1, y - 2, row, column)) % N;
    count = (count + dfs (x - 2, y - 1, row, column)) % N;
    count = (count + dfs (x - 2, y + 1, row, column)) % N;
    count = (count + dfs (x - 1, y + 2, row, column)) % N;
    count = (count + dfs (x + 1, y + 2, row, column)) % N;

    return 1;
}

int main ()
{
    //freopen ("a.txt", "r", stdin);
    int t, row, column, query, i, j;
    long long ans;
    factorial();
    scanf ("%d", &t);

    while (t --) {

        ans = 1;
        memset (matrix, 0, sizeof(matrix));
        memset (visited, false, sizeof(visited));
        scanf ("%d %d %d", &row, &column, &query);

        while (query--) {

            scanf ("%d %d", &i, &j);
            matrix[i - 1][j - 1] = 1;
        }

        for (i = 0; i < row; i++) {

            for (j = 0; j < column; j++) {

                if (matrix[i][j] && !(visited[i][j]))
                    dfs (i, j, row, column);

                ans = (ans * (fact[count + 1]) % N + N) % N;
                count = 0;
            }
        }

        printf("%lli\n", ans);
    }

    return 0;
}




/*
coding ninja solution
#include<bits/stdc++.h>
using namespace std;
 #define p int(1e9+7)
 int mat[1001][1001],n,m;
 #define ll long long int
 void input();
 void func();
 ll fac(ll);
 ll bfs(int,int);
 int main()
 {
 int t;
  cin>>t;
   while(t--)
    input();
     return 0;
      }
      void input()
       { int q;
       cin>>n>>m>>q;
        for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++)mat[i][j]=0;
         int x,y; while(q--)
          {
          cin >> x >> y;
           mat[x][y]=1;
           } func();
            } void func()
             {
             long long ans=1,t;
              for(int i=1;i<=n;i++)
               for(int j=1;j<=m;j++)
               { if(mat[i][j]==1)
               { t=bfs(i,j);
                ans=(ans*fac(t))%p;
                }
                }
                cout<<ans<<endl;
                }
                ll fac(ll t)
                {
                ll ans=1;
                for(ll i=1;i<=t;i++)ans=(ans*i)%p;
                return ans;
                }
                ll bfs(int i,int j)
                {
                ll t=1; mat[i][j]=2; // the eight conditions
                if(i-2>=1 && j+1<=m && mat[i-2][j+1]==1)
                t+=bfs(i-2,j+1);
                if(i-1>=1 && j+2<=m && mat[i-1][j+2]==1)t+=bfs(i-1,j+2); if(i+1<=n && j+2<=m && mat[i+1][j+2]==1)t+=bfs(i+1,j+2); if(i+2<=n && j+1<=m && mat[i+2][j+1]==1)t+=bfs(i+2,j+1); if(i-2>=1 && j-1>=1 && mat[i-2][j-1]==1)t+=bfs(i-2,j-1); if(i-1>=1 && j-2>=1 && mat[i-1][j-2]==1)t+=bfs(i-1,j-2); if(i+1<=n && j-2>=1 && mat[i+1][j-2]==1)t+=bfs(i+1,j-2); if(i+2<=n && j-1>=1 && mat[i+2][j-1]==1)t+=bfs(i+2,j-1); return t; }


*/
