#include<bits/stdc++.h>
using namespace std;


void maxPerimeter(int arr[], int n){

    sort(arr, arr+n, greater<int>());


    int maxi = 0;
     int a=0,b=0,c=0;

    for (int i = 0; i < n-2; i++){


        if (arr[i] < arr[i+1] + arr[i+2])
        {
            a=max(a,arr[i]);
            b=max(b,arr[i+1]);
            c=max(c,arr[i+2]);
            maxi = max(maxi, arr[i] + arr[i+1] + arr[i+2]);
            break;
        }
    }


    if (maxi)
        cout<<c<<" "<<b<<" "<<a;

    else
        cout <<"-1"<< endl;
}
int main() {

    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    maxPerimeter(arr,n);

	// Write your code here
}
