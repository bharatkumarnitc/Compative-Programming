#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadanesum(int arr[],int n)
{
    ll current_sum=0;
    ll best_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        current_sum+=arr[i];
        if(current_sum>best_sum)
        best_sum=current_sum;
        
        if(current_sum<0)
        current_sum=0;
        
    }
    
    return best_sum;
}

ll KCON(int arr[],int n,int k)
{
    
 ll kdsum=kadanesum(arr,n);
 if(k==1)
 return kdsum;
 
 ll prefixsum=0,postfixsum=0;
 ll bestprefix=INT_MIN,bestpostfix=INT_MIN;
 
 for(int i=0;i<n;i++)
 {
     prefixsum+=arr[i];
     bestprefix=max(bestprefix,prefixsum);
     
 }
 ll total=prefixsum;
 for(int i=n-1;i>=0;i--)
 {
     postfixsum+=arr[i];
     bestpostfix=max(postfixsum,bestpostfix);
     
 }
 ll ans;
 if(total<0)
 {
     ans=max(bestpostfix+bestprefix,kdsum);
 }
 else
 ans=max(bestpostfix+bestprefix+(total*(k-2)),kdsum);
 
    return ans;
}


int main() {
    
    int t;
    cin>>t;
    
    while(t--)
    {
        
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        
        cout<<KCON(arr,n,k)<<endl;
        
        
    }
	// your code goes here
	return 0;
}

