#include<bits/stdc++.h>
#include<vector>
using namespace std;
int solve(int n,vector<int>A){

    int arr[1000];//={0};
    int dp[1000];//={0};
    memset(arr,0,1000);
    memset(dp,0,1000);
    vector<int>::iterator it;
    dp[0]=0;
    dp[1]=A[0];
    for(it=A.begin(); it!=A.end();it++)
    {
      arr[(*it)]++;
    }



    for(int i=2;i<=1000;i++)
    {
        dp[i]=max((dp[i-2]+(i*arr[i])),dp[i-1]);
    }

    for(int i=0;i<n;i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    return dp[n];
}
int main()
{
    vector<int>A;
    int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}
