#include<bits/stdc++.h>
using namespace std;
int * cubefree()
{

    int arr[100000];
    memset(arr,0,100000);

    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=100;i++)
    {
        int num=pow(i,3);
        for(int j=1;j<=50;j++)
        {

            arr[num*j]=-1;
        }

    }

    int output[100000];
    int count=0;
    output[0]=0;
    for(int i=1;i<=100;i++)
    {
        if(arr[i]==0)
        {
            count++;
            output[i]=count;
        }
    }

    return output;
}


int main()
{

    int *output=cubefree();

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        if(output[n]!=-1)
            cout<<output[n];
        else
            cout<<" Not Cube Free"<<endl;



    }

	// Write your code here
	return 0;
}
