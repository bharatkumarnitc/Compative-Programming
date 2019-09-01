#include<bits/stdc++.h>
using namespace std;
bool chek(long int n,long int k)
{

   long  int sum=0;
    long int curr=n;
    while(curr>0)
    {

        sum=sum+min(curr,k);
        curr=curr-k;
        curr=curr-(curr/10);
    }

    if(2*sum>=n)
        return true;
    else
        return false;


}

long int binary(long int n)
{
    long int low=1,up=n;
    long int ans=-1;
    while(up>=low)
    {

        long int k=(low+up)/2;

        if(chek(n,k))
        {
            ans=k;
            up=k-1;
        }
        else
            low=k+1;
    }
return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long  int n;
    cin>>n;
    cout<<binary(n)<<endl;
	return 0;
}
