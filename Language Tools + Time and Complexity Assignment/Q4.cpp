#include<bits/stdc++.h>
using namespace std;
int main() 
{

    long int t;
    cin>>t;
    while(t--)
    {
        long int num;
        cin>>num;
        long int sum=0;
        while(num>0)
        {
            sum+=(num%10);
            num=num/10;
        
            
        }
        
       cout<<sum<<endl;
        
    }
    
    
	// Write your code here
}
