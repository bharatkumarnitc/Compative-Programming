#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55

int helper(int row,int col,bool **visited,char cake[NMAX][NMAX],int len)
{
    //std::cout<<row<<" "<<col<<endl;
    if(row < 0 || col < 0 || row >=len || col >=len){
        return 0;
    }
 if(visited[row][col]){
     return 0;
 }
    if(cake[row][col]=='0'){
        return 0;
    }
    visited[row][col]=true;
      int ans1 = helper(row,col+1,visited,cake,len);
      int ans2 = helper(row+1,col,visited,cake,len);
      int ans3 = helper(row,col-1,visited,cake,len);
      int ans4 = helper(row-1,col,visited,cake,len);
    return 1+ans1+ans2+ans3+ans4;
}

int solve(int n,char cake[NMAX][NMAX])
{

    bool **visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[n];
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            visited[i][j]=false;
    }
    
    int max=-1,value;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cake[i][j]=='1')
                  {
                  value=helper(i,j,visited,cake,n);
                  
                  }
                if(value>max)
                    max=value;
            //value=0;
           
        }      
    }

    return max;// Write your code here .
}
char cake[NMAX][NMAX];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}
