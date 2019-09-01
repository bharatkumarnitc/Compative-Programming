#include<bits/stdc++.h>
using namespace std;
class triplet
{

public:
    int x;
    int y;
    int gcd;
};

triplet ExtendEuclid(int a,int b)
{
    if(b==0)
    {
        triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;

    }

    triplet temp=ExtendEuclid(b,a%b);
    triplet ans;
    ans.gcd=temp.gcd;
    ans.x=temp.y;
    ans.y=temp.x-(a/b)*temp.y;
    return ans;

}

int multiplicative(int a,int m)
{

    triplet ans=ExtendEuclid(a,m);
    return ans.x;
}

int main()
{

  int a,m;
  cin>>a>>m;

  int t=multiplicative(a,m);
   cout<<t;

    return 0;
}
