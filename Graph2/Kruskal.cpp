#include<bits/stdc++.h>
using namespace std;
class edges
{

public:
    int src;
    int des;
    int weight;
};
int getparent(int v,int *parent)
{
    if(parent[v]==v)
        return v;
    else getparent((parent[v]),parent);

}
void kruskal(edges *input,int v,int e)
{

    int *parent=new int[v];

    for(int i=0;i<v;i++)
        parent[i]=i;

    edges *output=new edges[v];
    int count=0;
    int i=0;
    while(count<v-1)
    {
           edges current_vertex=input[i];
           int srcparent=getparent(current_vertex.src,parent);
           int desparent=getparent(current_vertex.des,parent);

           if(srcparent!=desparent)
           {
               output[count]=current_vertex;
               count++;
               parent[srcparent]=desparent;
           }

                   i++;
    }
    for(int i=0;i<v-1;i++)
	{

		if(output[i].src<output[i].des)
		{
			cout<<output[i].src<<" "<<output[i].des<<" "<<output[i].weight<<endl;
		}
		else
		cout<<output[i].des<<" "<<output[i].src<<" "<<output[i].weight<<endl;
	}



    delete parent;
    delete output;
}




bool cmp(edges a,edges b)
{

    return a.weight<b.weight;
}
int main()
{

    int v,e;
    cin>>v>>e;

    edges *input=new edges[e];

    for(int i=0;i<e;i++)
    {
        int src,des,w;
        cin>>src>>des>>w;
        input[i].src=src;
        input[i].des=des;
        input[i].weight=w;

    }

    sort(input,input+e,cmp);
    kruskal(input,v,e);
    //delete edges;
    return 0;
}


