#include <bits/stdc++.h>
using namespace std;
 long long *precal(long long *res,long long *phi, long long n )
  {
    for(long long i=1;i<=n;++i)
    phi[i] = i;
    for(long long i=2;i<=n;++i)
    {
    if(phi[i]==i)
    {
    for(int j=i;j<=n;j+=i)
    {
    phi[j] /= i;
    phi[j] *= i - 1;
    }
    }
    }
    for(long long i=1;i<=n;++i)
    {
    for(int j=i;j<=n;j+=i)
    res[j] += (i*phi[i]);
    } return phi;
    }
void func(long long n)
{
long long *res = new long long[1000010];
long long *phi = new long long[1000010];
phi = precal(res,phi,1000000);
long long ans = res[n] + 1;
ans *= n; ans /= 2;
printf("%lld\n",ans);
 }
int main()
{
    long long n;
    scanf ( "%lld", &n );
	func(n);
    return 0;
}
