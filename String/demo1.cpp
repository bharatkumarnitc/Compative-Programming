#include <bits/stdc++.h>
using namespace std;

int main() 
{
    
    vector<int> obj(1000);
    vector<int>::iterator it;
    obj[0]=0;
    obj[1]=1;
    
    for(int i=2;i<=1000;i++)
    {
    	obj[i]=obj[i-1]+obj[i-2];
	}
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
       for(int i=1;i<=n;i++)
       {
           int num;
           cin>>num;
             it=find(obj.begin(),obj.end(),num);
           if(it!=obj.end())
             cout<<num<<" ";
            
            
        }
        
        
        cout<<endl;
          }
	//code
	return 0;
}
