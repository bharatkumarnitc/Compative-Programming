#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int m,vector<int>u,vector<int>v)
{
    int **input=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        input[i]=new int[n+1];
        for(int j=0;j<=n;j++)
            input[i][j]=0;
    }
    
    for(int i=0;i<m;i++)
    {
        
            input[u[i]][v[i]]=1;
            input[v[i]][u[i]]=1;
        
    }
     
    
    int count=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            
            if(input[i][j]==1)
            {
                for(int k=1;k<=n;k++)
                {
                    if(i==k)
                        continue;
                    else if(input[j][k]==1)
                    {
                        
                        if(input[i][k]==1)
                            count++;
                    }
                    
                }
                
            }
            else
                continue;
            
            
        }
    }
    

return count/6;    
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
