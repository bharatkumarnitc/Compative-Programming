#include<bits/stdc++.h>
using namespace std;
 
bool DFS(bool **edge,bool *visited,vector<int> &vect,int sv,int v2,int n)
{
    visited[sv]=true;
    if(visited[v2]) return true;
 
    for(int i=0 ; i<n ; i++)
    {
        if(edge[sv][i] && (!visited[i])){
            vect.push_back(i);
            bool flag =  DFS(edge,visited,vect,i,v2,n);
            if(flag==true)
                return true;
            else
                vect.pop_back();
        }
    }
return false;
}
 
 
 
int main()
{
    int n,e;
    cin>>n>>e;
 
    bool **edge=new bool*[n];   
    for(int i=0 ; i<n ; i++)        
        edge[i]=new bool[n]();
    bool *visited=new bool[n]();
 
    while(e--)
    {
        int f,s;    
        cin>>f>>s;
        edge[f][s]=edge[s][f]=true;
    }
 
    int v1,v2;
    cin>>v1>>v2;
    if(v1==v2)
        {
            cout<<v1<<endl;
            return 0 ;
        }
 
 
    vector<int> probable_list;
    probable_list.push_back(v1);
 
 
    if( DFS(edge,visited,probable_list,v1,v2,n))
    {
        reverse(probable_list.begin(),probable_list.end());
 
        for(auto i : probable_list)
            cout<<i<<" ";
    }
 
 
    for(int i=0 ; i<n ; i++)
    delete[] edge[i];
    delete[] edge;
    delete[] visited;
}
