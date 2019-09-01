#include<bits/stdc++.h>
using namespace std;

int lps(string s)
{
	int count=0;
	int n=s.length();
	for(int i=0;i<=n;i++)
	{
	//odd length
	int l=i;
	int r=i;
	while(l>=0 && r<n &&s[l]==s[r])
	{
		count++;
		l--;
		r++;
		}	
		
			l=i;
	        r=i+1;
		
		while(l>=0 && r<n &&s[l]==s[r])
	{
		count++;
		l--;
		r++;
		}	
		
		
		
	}
	return count;
		
	}


int main()
{
	string s;
	cin>>s;
	cout<<lps(s)<<endl;
	
	
	return 0;
}
