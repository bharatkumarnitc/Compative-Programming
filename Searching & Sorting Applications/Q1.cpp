#include<bits/stdc++.h>
using namespace std;

bool chek(int *input,int n,int d)
{
	int count=0;
	int current_distance=input[0];
	
	for(int i=1;i<n;i++)
	{
		
		if(input[i]-current_distance>=d)
		{
			
			count++;
		}
		
		if(count==d)
		return true;
		
	}
	
	return false;
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n,c;
		cin >> n >> c;

		int positions[n];
		for(int i=0;i<n;i++)
		{
			cin >> positions[i];
		}
		
		int start=0;
		int end=positions[n-1]-positions[0];
		int ans=-1;
		while(start<=end)
		{
			
			int mid=(start+end)/2;
			if(chek(positions,n,mid))
			{
				ans=mid;
				start=mid+1;
				
			}
			else
			end=mid-1;
			
			
		}
		
		
		cout<<ans<<endl;
	}
	
	
	return 0;
}
