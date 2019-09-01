#include<bits/stdc++.h>
using namespace std;
int main() 
{
    
  int t;
    cin>>t;
    while(t--)
    {
        long int n;
        cin>>n;
        long int *p=new long int[n];
        for(int i=0;i<n;i++)
            cin>>p[i];
            //first method O(N)
             
             int mul=1;
            long int *result=new long int[n];
            for(int i=0;i<n;i++)
            {
               result[i]=mul;
               mul=mul*p[i];

			}
			mul=1;
			for(int i=n-1;i>=0;i--)
			{
				result[i]=result[i]*mul;
				mul=mul*p[i];
				
			}
            
            for(int i=0;i<n;i++)
            cout<<result[i]<<" ";
            
            //second method;
//        
//        for(int i=0;i<n;i++)
//        {
//            long int mul=1;
//            
//            for(int j=0;j<n;j++)
//            {
//                
//                if(i!=j)
//                    mul*=p[j];
//                
//            }
//            cout<<mul<<" ";
//                
//        }
//        cout<<endl;
       
        
    }

	// Write your code here
}
