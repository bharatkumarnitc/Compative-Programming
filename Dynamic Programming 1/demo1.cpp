#include <iostream>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int>* bf(int **edge,int n, int s,int e, int *visited)
{
    cout<<e<<endl;
    unordered_map<int,int>parent;
    vector<int>* v=new vector<int>;
    queue<int>q;
    q.push(s);
    visited[s]=1;
    int a=0;
while(!q.empty()&&a==0)
{
    int cv=q.front();
    q.pop();
    for(int i=0;i<n;i++)
    {
        if(edge[cv][i]==1&&visited[i]==0)
        {
                  cout<<i<<" ";
                  q.push(i);
                  visited[i]=1;
                   parent[i]=cv;
                if(i==e)
                {

                    a=1;
                  break;
                }
        }
    }
}

if(a==0)
return NULL;
else
{
    vector<int>*v1=new vector<int>();

    int curr=e;
    v1->push_back(e);
    while(curr!=s)
    {
        curr=parent[curr];
         v1->push_back(curr);
    }

        return v1;
    }
}

 void bfs(int **edge,int n, int s,int e, int *visited)
{
    vector<int> *t= bf(edge,n, s, e, visited);
    if(t!=NULL)
    {

     for(int i=0;i<t->size();i++)
     cout<<t->at(i)<<" ";
    }

}




int main()
{
    int n, e;
    cin >> n >> e;

   int **edge=new int*[n];
    for(int i=0;i<n;i++)
    {
        edge[i]=new int[n];
        for(int j=0;j<n;j++)
            edge[i][j]=0;
    }

    int *visited=new int[n];
    for(int i=0;i<n;i++)
            visited[i]=0;
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edge[f][s]=1;
        edge[s][f]=1;
    }

    int v1,v2;
    cin>>v1>>v2;
  bfs(edge,n,v1,v2,visited);

  return 0;
}
