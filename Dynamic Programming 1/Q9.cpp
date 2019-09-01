#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int countBST( int n)
{
    int mod=1000000007;
    int size=n+1;
    int dp[size]={0};
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {

            dp[i] = (dp[i] + (dp[i - j] * dp[j - 1])%mod)%mod;
        }
    }

    return dp[n]%mod;

}


int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
