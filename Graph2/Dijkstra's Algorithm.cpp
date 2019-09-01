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
	int *dist=new int[v];

	for(int i=0;i<v;i++)
	   dist[i]=INT_MAX;
	   dist[0]=0;
	    //parent[0]=-1;

	    for(int i=0;i<v-1;i++)
	    {
	    	//take minimum  vetrex that weight is minimum;
	    	int minvertex=getMinVertex(visited,dist,v);
	    	visited[minvertex]=true;


	    	//chek other connected vertices and store minimum weight
	    	for(int j=0;j<v;j++)
	    	{
	    		if(input[minvertex][j]!=0 && !visited[j])
	    		{
                    int currd=dist[minvertex]+input[minvertex][j];

	    			if(dist[j]>currd)
	    			{
	    				dist[j]=currd;

					}

				}


			}


		}



	for(int i=0;i<v;i++)
	{
        cout<<i<<" "<<dist[i]<<endl;
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
  //cout<<endl;
  prims(input,v);


return 0;
}
