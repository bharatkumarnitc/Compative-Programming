#include<bits/stdc++.h>
using namespace std;
#define MAXN 102
int helper(char arr[][MAXN],int n,int m,int **v,string s,int ri,int ci){
  if(s.size()==0)
  {
    return 1;
  }
  v[ri][ci]=1;
  if(ci-1>=0&&arr[ri][ci-1]==s[0]&&v[ri][ci-1]==0){
    int ans=helper(arr,n,m,v,s.substr(1),ri,ci-1);
    if(ans==1)
    {
      return 1;
    }
  }
  if(ci-1>=0&&ri-1>=0&&arr[ri-1][ci-1]==s[0]&&v[ri-1][ci-1]==0)
  {
    int ans=helper(arr,n,m,v,s.substr(1),ri-1,ci-1);
    if(ans==1){
      return 1;
    }
  }
  if(ri-1>=0&&arr[ri-1][ci]==s[0]&&v[ri-1][ci]==0){
    int ans=helper(arr,n,m,v,s.substr(1),ri-1,ci);
    if(ans==1){
      return 1;
    }
  }
  if(ri-1>=0&&ci+1<m&&arr[ri-1][ci+1]==s[0]&&v[ri-1][ci+1]==0){
    int ans=helper(arr,n,m,v,s.substr(1),ri-1,ci+1);
    if(ans==1){
      return 1;
    }
  }
  if(ci+1<m&&arr[ri][ci+1]==s[0]&&v[ri][ci+1]==0){
    int ans=helper(arr,n,m,v,s.substr(1),ri,ci+1);
    if(ans==1){
      return 1;
    }
  }
  if(ci+1<m&&ri+1<n&&arr[ri+1][ci+1]==s[0]&&v[ri+1][ci+1]==0){
    int ans=helper(arr,n,m,v,s.substr(1),ri+1,ci+1);
    if(ans==1){
      return 1;
    }
  }
  if(ri+1<n&&arr[ri+1][ci]==s[0]&&v[ri+1][ci]==0){
    int ans=helper(arr,n,m,v,s.substr(1),ri+1,ci);
    if(ans==1){
      return 1;
    }
  }
  if(ri+1<n&&ci-1>=0&&arr[ri+1][ci-1]==s[0]&&v[ri+1][ci-1]==0){
    int ans=helper(arr,n,m,v,s.substr(1),ri+1,ci-1);
    if(ans==1){
      return 1;
    }
  }
  v[ri][ci]=0;
  return 0;
}
int solve(char Graph[][MAXN],int n, int m){
  string s="CODINGNINJA";
  int **visited=new int*[n];
  for(int i=0;i<n;i++){
    visited[i]=new int[m];
    for(int l=0;l<m;l++){
      visited[i][l] = 0;
    }
  }
  for(int i=0;i<n;i++){
    for(int l=0;l<m;l++){
      if(Graph[i][l]=='C'){
        int ans=helper(Graph,n,m,visited,s.substr(1),i,l);
        if(ans==1){
          return 1;
        }
      }
    }
  }
  return 0;
}
int main()
{
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}
