#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    for(int i=0;i<(n/2);i++)
    {
        
        int sum;
        sum=arr[i]+arr[n-(i+1)];
        cout<<sum/10<<" ";
        cout<<sum%10<<endl;
        
    }
    
	return 0;
}

