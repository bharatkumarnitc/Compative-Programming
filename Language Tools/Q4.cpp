#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n;
    cin>>n;
    string s;
          cin>>s;
    
    map<char,int>obj;
    
    for(int i=0;i<n;i++)
       obj[s[i]]++;
       cout<<obj['a']<<" "<<obj['s']<<" "<<obj['p'];
     
	return 0;
}

