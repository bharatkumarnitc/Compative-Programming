#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string str;
    ll n,number,x,y;
    cin>>number>>x>>y;
   //getline(cin, str);
    cin >> str;
    if(str[0]=='0')
        {n=1;}
    else
        n=0;

    for(ll i=0;i<str.length();i++)
    {
        if(str[i]=='1'&&str[i+1]=='0')  //group bn rhe h
        {
            n++;
        }
    }


        ll cost=((n-1)*min(x,y))+y;    //zero one ek sth aane ke baad
        cout<<cost;


	return 0;
}
