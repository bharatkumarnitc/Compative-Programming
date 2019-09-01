#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int A[1003];

int main()
{

    int N, K, L;
    cin>>N>>K>>L;

    for(int i=1; i<=N; i++)
        cin>>A[i];

    int ans = 1000000000;

    for(int i=1; i<=1000; i++)
    {
        int inc = 0, dec = 0;

        for(int j=1; j<=N; j++)
        {
            if(A[j]>=i)
                dec+= A[j]-i;
            else
                inc+= i-A[j];
        }

        if(inc>=dec)
            ans = min(ans, K*dec + L*(inc-dec));
    }

    cout<<ans;

    return 0;
}
