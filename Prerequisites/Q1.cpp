#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n;
    cin>>n;
     long int *p= new long int[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
        long int sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
        	if(i%2==0)
        	{
        		if(p[i]%2==0)
        	   sum1+=p[i];	
        		
			}
			else
			{
				
              if(p[i]%2!=0)
			  sum2+=p[i];				
			}
			
        	
		}
		
		cout<<sum1<<" "<<sum2<<endl;
	return 0;
}

