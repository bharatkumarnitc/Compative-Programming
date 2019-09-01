#include <bits/stdc++.h>
using namespace std;

int magic_gird(int **arr,int r,int c)
{
     int **output=new int*[r];
        for(int i=0;i<r;i++)
        output[i]=new int[c];

    if(arr[r-1][c-1]==0)
        output[r-1][c-1]=1;

    for(int i=r-2;i>=0;i--)
    {

        output[i][c-1]=output[i+1][c-1]-arr[i+1][c-1];
        if(output[i][c-1]<=0)
             output[i][c-1]=1;
    }


    for(int  j=c-2;j>=0;j--)
    {
        output[r-1][j]=output[r-1][j+1]-arr[r-1][j+1];
        if(output[r-1][j]<=0)
            output[r-1][j]=1;
    }



    for(int i=r-2;i>=0;i--)
    {
        for( int j=c-2;j>=0;j--)
        {

            output[i][j]=min(output[i+1][j]-arr[i+1][j],output[i][j+1]-arr[i][j+1]);
             if(output[i][j] <= 0) {
    			output[i][j] = 1;
			}


        }
    }
     for(int i=0;i<r;i++)
    {

        for(int j=0;j<c;j++)
            cout<<output[i][j]<<" ";
        cout<<endl;
    }

    return output[0][0];
}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int r,c;
        cin>>r>>c;

        int **arr=new int*[r];
        for(int i=0;i<r;i++)
        arr[i]=new int[c];

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            cin>>arr[i][j];
        }


        cout<<magic_gird(arr,r,c)<<endl;


    }

    return 0;
}
