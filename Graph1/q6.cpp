#include <bits/stdc++.h>
using namespace std;
vector<int>obj;
void DFS(int **input,int V,int st,bool *visit)
{
    obj.push_back(st);
    //cout<<st<<" ";
    visit[st]=true;
    
    for(int i=0;i<V;i++)
    {
        if(i==st)
            continue;
        if(input[st][i]==1)
        {
           if(visit[i])
               continue;
            DFS(input,V,i,visit); 
        }
        
        
    }
    
    
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    
 int **input=new int*[V];
    for(int i=0;i<V;i++)
    {
        input[i]=new int[V];
        for(int j=0;j<V;j++)
            input[i][j]=0;
    }
    
    while(E--)
    {
        int st,end;
        cin>>st>>end;
        input[st][end]=1;
        input[end][st]=1;
    }
    
   
    bool *visit=new bool[V];
    
    for(int i=0;i<V;i++)
    {
        if(visit[i]==false)
        {
        DFS(input,V,i,visit);
        for(int i=0;i<obj.size();i++)
        {
            sort(obj.begin(),obj.end());
            cout<<obj[i]<<" ";
            
        }
            obj.clear();
            cout<<endl;
        }
        
        
    }

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */

  return 0;
}

