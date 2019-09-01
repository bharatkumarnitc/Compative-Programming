#include<bits/stdc++.h>
using namespace std;

int kadane(int *arr,int n)
{
	int currentsum=0;
	int bestsum=0;
		for(int i=0;i<n;i++)
		{
			
			currentsum+=arr[i];
			if(currentsum>bestsum)
			bestsum=currentsum;
			
			if(currentsum<0)
			currentsum=0;
		}
		
		
	return bestsum;
	
}
int main()
{
	
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	  {
	  	
	  	int num;
	  	cin>>num;
	  	arr[i]=num;
	  }
	
	
	cout<<kadane(arr,n);
	
	return 0;
}
