#include<bits/stdc++.h>
using namespace std;
int main() {

    int n,t;
    cin>>n>>t;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
   int start=0,end=0,sum=arr[0];
    
    while(start<n && end<n)
    {
        
        if(sum<t)
        {
            end++;
            sum+=arr[end];
        }
        else if(sum>t)
        {
            sum-=arr[start];
            start++;
        }
        else
        {
            cout<<"true"<<endl;
            for(int k=start;k<=end;k++)
                cout<<arr[k]<<" ";
            cout<<endl;
            return 0;
        }
        
        
    }
    cout<<"false"<<endl;
    return 0;
	// Write your code here
}
