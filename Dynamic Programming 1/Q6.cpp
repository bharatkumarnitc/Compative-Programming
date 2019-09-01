#include<bits/stdc++.h>
using namespace std;
long long int kadane(vector<long long int> v)
{

	int n=v.size();
	int i,j;
	long long int ret=0,me=INT_MIN,csum=0;
	for(int i=0;i<n;i++)
	{
		csum+=v[i];
		if(csum<0)
		csum=0;
		ret=max(ret,csum);
		me=max(me,v[i]);
	}
	if(me<0)
	return me;
	else
	return ret;
}

int main()
{
	long long int maxsum=-INT_MIN,sum,i,j,k,n,m;
	cin>>n>>m;
	int **input=new int*[n];
	for(int i=0;i<n;i++)
	input[i]=new int[m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cin>>input[i][j];
	}

	for(int l=0;l<m;l++)
	{
		vector<long long int> v(n,0);
		for(int r=l;r<m;r++)
		{

			for(int i=0;i<n

			;i++)
			{
			v[i]+=input[i][r];
			}
			  cout<<endl;
			  maxsum=max(kadane(v),maxsum);
		}
	}
	cout<<maxsum;

	return 0;
}
