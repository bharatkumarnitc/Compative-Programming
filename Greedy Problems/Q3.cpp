#include <bits/stdc++.h>
using namespace std;
struct activity
{

    int start;
    int end;
};


bool cmp(activity a,activity b)
{
	return a.end < b.end;
}

int main() {

   int n;
        cin>>n;
        activity arr[n];
        for(int i=0;i<n;i++)
        {
           cin>>arr[i].start>>arr[i].end;
        }

        sort(arr,arr+n,cmp);

        int count=1;
        int st=arr[0].start;
        int en=arr[0].end;

        for(int i=0;i<n;i++)
        {

        	if(en<=arr[i].start)
        	{
        		en=arr[i].end;
        		count++;
			}


		}

        cout<<count<<endl;


	//code
	return 0;
}
