#include<bits/stdc++.h>
using namespace std;

int getparent(int v,int *parent)
{
    if(parent[v]==v)
        return v;
    else getparent((parent[v]),parent);

}
void kruskal(edge *input,int v,int e)
{

    int *parent=new int[v];
    for(int i=0;i<n;i++)
        parent[i]=i;

    int *output=new int[v];
    int count=0;
    int i=0;
    while(count<v-1)
    {
           edge current_vertex=input[i];
           int srcparent=getparent(current_vertex.src,parent);
           int desparent=getparent(current_vertex.des,parnet);

           if(srcparent!=desparent)
           {
               output[count]=current_vertex;
               count++;
               parent[srcparent]=desparent;
           }

                   i++;
    }



    delete parent;
    delete output;
}


class edges
{

public:
    int src;
    int des;
    int weight;
};

bool cmp(edges a,edges b)
{

    return a.weight<b.weight;
}
void main()
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



    delete edges;
    return 0;
}


