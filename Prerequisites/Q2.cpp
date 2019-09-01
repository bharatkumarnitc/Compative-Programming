#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
   cin>>n;
   int arr[n][n];
   for(int i=0;i<n;i++)
   {
   	for(int j=0;j<n;j++)
   	    cin>>arr[i][j];

   }
    int sum=0;
   
   for(int i=0;i<n;i++)
   {
   	
   	for(int j=0;j<n;j++)
   	{

   		if(i==0 || j==0 || i==n-1|| j==n-1)
   		sum+=arr[i][j];   		
	   }
   }
  // cout<<sum;
   sum=sum-(arr[0][0]+arr[n-1][n-1]+arr[0][n-1]+arr[n-1][0]);
   //cout<<sum;
   int sum1=0;
   for(int i=0;i<n;i++)
   {
   	for(int j=0;j<n;j++)
   	{
   		if(i==j)
   		sum+=arr[i][j];
   		
   		if((i+j)==n-1 && i!=j)
   		sum1+=arr[i][j];
	   }
   }
   cout<<(sum+sum1);
   
   
}

