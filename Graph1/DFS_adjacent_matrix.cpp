#include<bits/stdc++.h>
using namespace std;

void print(int **matrix,int v,int st,bool *visited)
{
	cout<<st<<endl;
	visited[st]=true;
	
	for(int i=0;i<v;i++)
	{
		
		if(i==st)
		continue;
		if(matrix[st][i]==1)
		{
			if(visited[i])
	     	continue;
	     	
	     	print(matrix,v,i,visited);
		}
		
		
		
	}
	
	
}

int main()
{
	
  int v,e;
  cin>>v>>e;
  
 int **matrix=new int*[v];
 
for(int i=0;i<v;i++)
{
	matrix[i]=new int[v];
	
	for(int j=0;j<v;j++)
	{
		
		matrix[i][j]=0;
		
	}
	
	}	
while(e--)
{
	
	int st,end;
	cin>>st>>end;
	matrix[st][end]=1;
	matrix[end][st]=1;
	}	
	
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
	visited[i]=false;
	print(matrix,v,0,visited);   //send matrix total vertices and starting edges
	
	
	return 0;
}
