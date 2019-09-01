#include <iostream>
#include <stdio.h>
#include "solution.h"
using namespace std;

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int getMin(int *arr, int n)
{
    int dp1[n];
    int dp2[n];

    dp1[0]=1;
    for(int i=1;i<n;i++)
    {

        if(arr[i]>arr[i-1])
        {

            dp1[i]=dp1[i-1]+1;
        }
        else
            dp1[i]=1;
    }

    dp2[n-1]=1;
    for(int j=n-2;j>=0;j--)
    {
        if(arr[j]>arr[j+1])
            dp2[j]=dp2[j+1]+1;
        else
            dp2[j]=1;


    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        //std::cout<<dp1[i]<<" "<<dp2[i];
         sum+=max(dp1[i],dp2[i]);
    }


    return sum;

}

int main(){

    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << getMin(arr, n);
    delete []arr;
}
