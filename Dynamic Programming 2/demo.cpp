#include<bits/stdc++.h>
using namespace std;

void slove(long long int n,long long int k,long long int arr[])
{
	sort(arr,arr+n);
	vector<long long int> sum(n+1,0);
	long long int c=0,ans=-1,z;
	int i;
	sum[0]=0;
	for(int i=0;i<n;i++)
	sum[i+1]=sum[i]+arr[i];
	for(int i=0;i<k;i++)
	c+=arr[i]*(2*i+1);
	
	for(int i=0;i+k<=n;i++)
	{
		//k numvers starting from i;
		z=c-k*(sum[k+i]-sum[i]);
		if(ans==-1)
		ans=z;
		else
		ans=min(z,ans);
		//change c for next
		if(i+k<=n)
		c=c-2*(sum[k+i]-sum[i+1])-arr[i]+(2*k-1)*arr[i+k];
		
	}
cout<<ans;	
}
int main()
{
	long long int N,K;
	
	cin>>N>>K;
	long long int A[N];
	for(int i=0;i<N;i++)
	cin>>A[i];
	slove(N,K,A);
	
	
	return 0;
}
