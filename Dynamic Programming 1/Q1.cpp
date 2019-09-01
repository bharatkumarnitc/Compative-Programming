#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
int number(string s)
{
  int *a=new int[s.size()+1];

  a[0]=1;
  a[1]=1;

  for(int i=2;i<=s.size();i++)
  {
    a[i]=0;
    if(s[i-1]!='0')
   {
    a[i]=a[i-1];
   }
     if((s[i-2]-'0')*10 + (s[i-1]-'0') <=26 && (s[i-2]-'0')*10 + (s[i-1]-'0') >=10)
    {
      a[i]=(a[i]+a[i-2])%m;
    }
  }

  int ans=a[s.size()]%m;
  delete [] a;
  return ans;
}
int main()
{

  string s;
  cin>>s;

  while(s[0]!='0')
  {

    int n=number(s);
    cout<<n<<endl;
    s.clear();
    cin>>s;

  }

    return 0;
}
