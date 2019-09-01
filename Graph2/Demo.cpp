#include<bits/stdc++.h>
using namespace std;
#define MAXN 102

void DFS(char Graph[][MAXN],int i,int j,map<char,bool>&obj)
{
	
	
	
	if(i>-1 && j>-1)
	{
		
	obj[Graph[i][j]]=true;
           	
		if(Graph[i][j]=='O' ||Graph[i][j]=='D' ||Graph[i][j]=='I' ||Graph[i][j]=='N' ||Graph[i][j]=='I' ||Graph[i][j]=='N' ||Graph[i][j]=='J' || Graph[i][j]=='A')
	    {
               DFS(Graph,i-1,j-1,obj); 
               DFS(Graph,i-1,j,obj);
               DFS(Graph,i,j+1,obj);
               DFS(Graph,i,j-1,obj);
               DFS(Graph,i,j+1,obj);
               DFS(Graph,i+1,j-1,obj);
               DFS(Graph,i+1,j,obj);
               DFS(Graph,i+1,j+1,obj);
                
                
        
            
            
        }
    }
		
	
}
int solve(char Graph[][MAXN],int N, int M)
{
    
    map<char,bool> obj;
    map<char,bool>::iterator it;
    obj['C']=false;
    obj['O']=false;
    obj['D']=false;
    obj['I']=false;
    obj['N']=false;
    obj['G']=false;
    obj['N']=false;
    obj['I']=false;
    obj['N']=false;
    obj['J']=false;
    obj['A']=false;
    
    for(int i=0;i<N;i++)
    {
        
        for(int j=0;j<M;j++)
        {
            
            if(Graph[i][j]=='C')
            {
               obj['C']=true;
               DFS(Graph,i-1,j-1,obj); 
               DFS(Graph,i-1,j,obj);
               DFS(Graph,i,j+1,obj);
               DFS(Graph,i,j-1,obj);
               DFS(Graph,i,j+1,obj);
               DFS(Graph,i+1,j-1,obj);
               DFS(Graph,i+1,j,obj);
               DFS(Graph,i+1,j+1,obj);
                
                
            }
            
            
        }
    }
    
    for(it=obj.begin();it!=obj.end();it++)
    {
    	if(it->second==false)
    	{
    		
    		return 0;
		}
	}
    return 1;
	// Write your code here.
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
