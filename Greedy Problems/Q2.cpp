#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;

    int *arr=new int[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n,greater<int>());
    long int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+(arr[i]*pow(2,i));


    }
     cout<<sum;
    //Write your code here
    return 0;
}
