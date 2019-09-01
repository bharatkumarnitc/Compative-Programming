#include<bits/stdc++.h>
using namespace std;
int maxsubarray(int arr[],int n)
{
	int best_max=1;
	int min_end=1;
	int max_end=1;
	for(int i=0;i<n;i++)
	{
	   if(arr[i]>0)
	   {
	   	
	   	max_end=max_end*arr[i];
	   	min_end=min(1,arr[i]);
	   	 
		}	
		
		else if(arr[i]<0)
		{
		  int temp=max_end;
		    max_end=max(1,min_end*arr[i]);
			min_end=temp*arr[i];		
		}
		else
		{
			min_end=1;
			max_end=1;
			
		
		}
		
		if(max_end > best_max)
		best_max=max_end;
	}
	
	
	return best_max;
}

int main() {
    
    int t;
    cin>>t;
    
    while(t--)
    {
        
        int n,k;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        
        cout<<maxsubarray(arr,n)<<endl;
        
        
    }
	// your code goes here
	return 0;
}

