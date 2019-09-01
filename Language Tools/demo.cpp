#include<bits/stdc++.h>
using namespace std;

struct arr
{
	int arr;
	int dep;
};
bool cmp(arr a,arr b)
{
	
	return a.dep < b.dep;
}
int main()
{

  int n;
  cin>>n;
  
  arr *input=new arr[n];
   for(int i=0;i<n;i++)
  	cin>>input[i].arr;
	  
	   for(int i=0;i<n;i++)
  	    cin>>input[i].dep;
	  sort(input,input+n,cmp);
	  	
	   for(int i=0;i<n;i++)
  {
  	
  	cout<<input[i].arr<<" "<<input[i].dep<<endl;
	  }	
	
	sort(input,input+n,cmp);
	
	int count=1;
	int st=input[0].arr;
	int end=input[0].dep;
	for(int i=1;i<n;i++)
	{
		if(end<=input[i].arr)
		{
			count++;
			st=input[i].dep;
			end=input[i].arr;
		}
		
	}
	cout<<count<<endl;
	
}
