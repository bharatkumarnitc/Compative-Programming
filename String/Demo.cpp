#include <bits/stdc++.h>
using namespace std;

int main() 
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,m,k;
        cin>>n>>m>>k;
        map<int,int>arr1,arr2;
        map<int,int>::iterator it;
        while(n--)
        {
            int num;
            cin>>num;
            arr1[num]++;
        }
        while(m--)
        {
            int num;
            cin>>num;
            arr2[num]++;
        }
        
        for(it=arr1.begin();it!=arr1.end();it++)
        {
            
            int num=k-(it->first);
            
            if(arr2[num]==1)
            cout<<(it->first)<<" "<<num<<",";
            
        }
        
        cout<<"\n";
    }
    
	//code
	return 0;
}
