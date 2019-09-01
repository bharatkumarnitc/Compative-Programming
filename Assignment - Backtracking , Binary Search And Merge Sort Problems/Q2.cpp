#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin>>t;
    while(t--)
    {


        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];


       int flag=1;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1]){

            if(arr[i]-arr[i+1]==1)
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;

            }
            else
            {
                flag=0;
                break;
            }
            }

        }
        if(flag==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;


    }

	return 0;
}
