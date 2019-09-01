#include<bits/stdc++.h>
using namespace std;

class Edge
{
 public:
   int src;
   int dest;
   int weight;	
	
};
bool cmp(Edge e1,Edge e2)
{
	return e1.weight<e2.weight;
}
int getParent(int v,int *parent)
{
	if(parent[v]==v)
	return v;
	
	return getParent(parent[v],parent);
}
Edge *kruskal(Edge *input,int v,int e)
{
	
	sort(input,input+e,cmp);
	
	Edge *output=new Edge[v-1];
	int *parent=new int[v];
	for(int i=0;i<v;i++)
	parent[i]=i;
	
	int count=0;
	int i=0;
	while(count<(v-1))
	{
		
		Edge currentEdge=input[i];
		int srcparent=getParent(currentEdge.src,parent);
		int desparent=getParent(currentEdge.dest,parent);
		
		if(srcparent!=desparent)
		{
			
			output[count]=currentEdge;
			count+=1;
			parent[srcparent]=desparent;
		}
		
		i+=1;
	}
	
	
	return output;
}
int main()
{
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int v,e;
	cin>>v>>e;
	
	Edge *input=new Edge[e];
	for(int i=0;i<e;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		input[i].src=s;
		input[i].dest=d;
		input[i].weight=w;
	}
	Edge *output=kruskal(input,v,e);
	for(int i=0;i<v-1;i++)
	{
		
		if(output[i].src<output[i].dest)
		{
			cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		}
		else
		cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
	}
	return 0;
}
