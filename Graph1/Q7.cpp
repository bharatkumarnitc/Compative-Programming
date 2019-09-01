#include<iostream>
#include<vector>
using namespace std;
void DFS(int **input,int v,int st,bool *visit)
{
    
    visit[st]=true;
    
    for(int i=0;i<=v;i++)
    {
        
        if(i==st)
            continue;
        if(input[st][i]==1)
        {
            
            if(visit[i])
                continue;
            DFS(input,v,i,visit);
            
        }
        
    }
    
    
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
    int count=0;
    int **input=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        input[i]=new int[n+1];
        for(int j=0;j<=n;j++)
            input[i][j]=0;
    }
    
   
   for(int i=0;i<m;i++) 
   {
       int r=u[i];
       int c=v[i];
       //cout<<r<<" "<<c<<endl;
       input[r][c]=1;
       input[c][r]=1;
   }
       
    bool *visit=new bool[n];
    for(int i=0;i<=n;i++)
        visit[i]=false;
    
    for(int i=0;i<=n;i++)
    {
        
        if(visit[i]==false)
        {
            count++;
            DFS(input,n,i,visit);
        }
        
    }
    
    return count-1;
    
	// Write your code here .
}
int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
