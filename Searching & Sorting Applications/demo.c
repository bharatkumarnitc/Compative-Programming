#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count=0;
    int n,m,k;
    cin>>n>>m>>k;

    while(n>0)
    {
        n-m;

        for(int i=1;i<=k;i++)
        {
            n-i;
            count++;
        }

        count++;
    }

    cout<<count;
}
