#include <bits/stdc++.h>
using namespace std;
long long int counti;

void merge(long long int *a, int low,long long int mid,long long int high)
{
   // cout<<count<<" ";
    int b[1000010];
    long long int i = low, j = mid + 1, k = 0;
    long long int length = high - mid;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i];
            counti += (a[i] * length);
            i++;
        }
        else
        {
            b[k++] = a[j++];
            length--;
        }
    }
    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    k--;
    while (k >= 0)
    {
        a[low + k] = b[k];
        k--;
    }
}

void mergesort(long long int *a,long long int low,long long int high)
{
    if (low < high)
    {
        int m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

int main()
{
    int testCases;
    long long int arr[1000010], i , n;

   cin>>testCases;

    while(testCases--)
    {
        cin>>n;

        for(i = 0 ; i < n ; i++)
        cin>>arr[i];

        counti = 0;
        mergesort(arr, 0 , n - 1);

        cout<<counti;
    }

    return 0;
}
