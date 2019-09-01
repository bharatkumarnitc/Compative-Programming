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


int main()
{

  int a,b;
  cin>>a>>b;

    triplet temp;
  if(a>b)
  {

    temp=ExtendEuclid(a,b);
    cout<<temp.gcd<<" " <<temp.x<<" "<<temp.y<<endl;
  }
  //cout<<
  else
  {

     temp=ExtendEuclid(b,a);
     cout<<temp.gcd<<"" <<temp.x<<" "<<temp.y<<endl;
  }
    //cout<<ExtendEuclid(b,a);


    return 0;
}
