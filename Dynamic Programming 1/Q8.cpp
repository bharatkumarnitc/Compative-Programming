#include<iostream>

using namespace std;

int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}
int findMaxSquareWithAllZeros(int** arr, int row, int col){

    int **output=new int*[row];
    for(int i=0;i<row;i++)
    {
        output[i]=new int[col];

    }

    for(int i=0;i<col;i++)
    {
        if(arr[0][i]==1)
            output[0][i]=0;
        else
            output[0][i]=1;
    }

    for(int i=0;i<row;i++)
    {
        if(arr[i][0]==1)
            output[i][0]=0;
        else
            output[i][0]=1;
    }

    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {

          if(arr[i][j]==1)
              output[i][j]=0;
            else
                output[i][j]=1+min(output[i-1][j-1],min(output[i][j-1],output[i-1][j]));
        }
    }


    int maxi=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)

            if(output[i][j]>maxi)
                maxi=output[i][j];
    }

    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */

    return maxi;
}
int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}
