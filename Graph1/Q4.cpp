#include <bits/stdc++.h>
using namespace std;

vector<int> *getPath(int **edges,int n,int sv,int ev)
{
    queue<int> q;
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    
    q.push(sv);
    visited[sv]=true;
    unordered_map<int,int> m;
    bool done= false;
    
    while(!q.empty()&&!done)
    {
        int front = q.front();
        q.pop();
        
        for(int i=0;i<n;i++)
		{
            if(edges[front][i]==1 &&visited[i]==false)
			{
                q.push(i);
                visited[i]=true;
                m[i]=front;
                if(i==ev){
                    done=true;
                    break;
                }
            }
        }
    }
    
    delete [] visited;
    
    if(!done)
	{
        return NULL;
    }
	else
	{
        vector<int> *output = new vector<int>();
        int curr = ev;
        output->push_back(curr);
        while(curr != sv){
            curr = m[curr];
            output->push_back(curr);
        }
        return output;
    }
    
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    int **edges = new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    for(int i =0;i<E;i++){
        int x,y;
        cin>>x>>y;
        edges[x][y]=1;
        edges[y][x]=1;
    }
    int sv,ev;
    cin>>sv>>ev;
    
    vector<int> *output = getPath(edges,V,sv,ev);
    if(output!=NULL){
        for(int i = 0;i<output->size();i++){
            cout<<output->at(i)<<" ";
        }
    }

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */

  return 0;
}
