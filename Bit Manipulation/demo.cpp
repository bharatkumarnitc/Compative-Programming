#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
void BFS(int **edges,int n,int sv,int ev,bool *visited,unordered_map<int,int>map1)
{
  int front=0;
  int key=0;
  queue<int>elements;
  elements.push(sv);
  visited[sv]=true;

  while(elements.size()!=0)
  {
    front=elements.front();


    if(front==ev)
    {
      break;
    }

    visited[front]=true;
    elements.pop();
    for(int i=0;i<n;i++)
    {
      if(i==sv)
      {
        continue;
      }
      if(edges[front][i]==1 && !visited[i])
      {

        map1[i]=front;
        elements.push(i);

      }
    }

  }

//unordered_map<int,int> :: iterator it=map1.begin() ;

vector<int> *output = new vector<int>();
        int curr = ev;
        output->push_back(curr);
        cout<<curr<<" ";
        while(curr != sv)
        {
            curr = map1[curr];
            cout<<curr<<" ";
            //output->push_back(curr);
        }
        //return output;

}


int main()
{
  int v;
  int e;

  cin>>v;

  cin>>e;

//create the 2D array

int **edges=new int*[v];
for(int i=0;i<v;i++)
{
  edges[i]=new int[v];

  for(int j=0;j<v;j++)
  {
    edges[i][j]=0;
  }

}

for(int i=0;i<e;i++)
{
  int f;
  int s;
  cin>>f>>s;
  edges[f][s]=1;
  edges[s][f]=1;
}

bool *visited=new bool[v];
for(int i=0;i<v;i++)
{
  visited[i]=false;
}

int sv;
int ev;

cin>>sv;

cin>>ev;
unordered_map<int,int>map1;
BFS(edges,v,sv,ev,visited,map1);


}
