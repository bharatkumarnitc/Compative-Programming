#include <bits/stdc++.h>
using namespace std;

void print(int **matrix,int V,bool *visit,int st)
{

    queue<int>obj;
    obj.push(st);
    
    while(!obj.empty())
    {
       int current_index=obj.front();
          cout<<current_index<<" ";
        obj.pop();
        visit[st]=true;
        for(int i=0;i<V;i++)
        {
            if(matrix[current_index][i]==1 && !visit[i])
            {
              
                obj.push(i);
                    visit[i]=true;
                
                
            }
            
        }
        
        
    }
    
    
}

int main() {
    int V, E;
    cin >> V >> E;
    
    int **matrix=new int*[V];
    
    for(int i=0;i<V;i++)
    {
        matrix[i]=new int[V];
        
        for(int j=0;j<V;j++)
            matrix[i][j]=0;
        
    }
    
    while(E--)
    {
        int st,end;
        cin>>st>>end;
        matrix[st][end]=1;
        matrix[end][st]=1;
        
    }
    
    bool *visit=new bool[V];
    
    for(int i=0;i<V;i++)
        visit[i]=false;
    print(matrix,V,visit,0);
    

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */

  return 0;
}

