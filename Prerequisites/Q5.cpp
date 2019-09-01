#include<bits/stdc++.h>
using namespace std;


void profit( int arr[],int n)
{
    
    int min=0;
    int max=0;
    int i=1;
    while(i<n)
    {
        
        if(arr[i]<arr[min])
            min=i;
        int cost=arr[i]-arr[min];
        if(cost>max)
            max=cost;
        
        i++;
        
    }
    
    
    cout<<max;
    
    
}


int main() {
    
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    
    profit(arr,n);
   

	// Write your code here
}
