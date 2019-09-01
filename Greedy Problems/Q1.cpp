// arr - input array
// n - size of array
#include<bits/stdc++.h>
using namespace std;
int minAbsoluteDiff(int arr[], int n)
{
    int x;
    int min;
    std::sort(arr,arr+n);
    min=abs(arr[0]-arr[1]);
    for(int i=0;i<n;i++)
    {
         x=abs(arr[i]-arr[i+1]);
        if(xe<=min)
            min=x;

    }

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
return min;

}



int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];

	for(int i = 0; i < size; i++)
		cin >> input[i];

	cout<< minAbsoluteDiff(input,size) << endl;

	return 0;

}

