#include<bits/stdc++.h>
using namespace std;

int getMinVertex(bool *visited,int *weight,int v)
{

	int min=-1;

	for(int i=0;i<v;i++)
	{

		if(!visited[i] && (min==-1 || weight[min]>weight[i]))
		min=i;

	}

	return min;
}


void prims(int **input,int v)
{

	bool *visited=new bool[v];
	int *parent=new int[v];
	int *weight=new int[v];

	for(int i=0;i<v;i++)
	   weight[i]=INT_MAX;
	   weight[0]=0;
	    parent[0]=-1;

	    for(int i=0;i<v-1;i++)
	    {

	    	int minvertex=getMinVertex(visited,weight,v);
	    	visited[minvertex]=true;

	    	for(int j=0;j<v;j++)
	    	{
	    		if(input[minvertex][j]!=0 && !visited[j])
	    		{

	    			if(weight[j]>input[minvertex][j])
	    			{
	    				weight[j]=input[minvertex][j];
	    				parent[j]=minvertex;

					}

				}


			}


		}



	for(int i=1;i<v;i++)
	{
		if(parent[i]<=i)
		{
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
		}
		else
		cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
	}
}


int main()
{
  int v,e;
  cin>>v>>e;

  int **input=new int*[v];
  for(int i=0;i<v;i++)
  {
  	input[i]=new int[v];
  	for(int j=0;j<v;j++)
  	{
  		input[i][j]=0;
	  }
  }

  while(e--)
  {
  	int st,end,w;
  	cin>>st>>end>>w;
  	input[st][end]=w;
  	input[end][st]=w;

  }
  prims(input,v);


return 0;
}
