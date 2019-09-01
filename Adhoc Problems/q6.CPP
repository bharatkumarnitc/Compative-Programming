#include<bits/stdc++.h>
using namespace std;
int main() {

    int n;
    cin>>n;
    long int *input=new long int[n];
    //long int *output=new int[n];
    for(int i=0;i<n;i++)
        cin>>input[i];
    int count=0;
    int flag=0;
    for(int i=n-1;i>=0;i--)
    {

        if(input[i]==i+1)
            continue;
        else if(input[i]!=i+1)
        {
            if(input[i-1]==i+1)
            {
                int temp=input[i-1];
                input[i-1]=input[i];
                input[i]=temp;
                count++;
            }
            else if( input[i-2]==i+1)
            {
                input[i-2]=input[i-1];
                input[i-1]=input[i];
                input[i]=i+1;
                count=count+2;


            }
            else
            {
                flag=1;
                break;
            }



        }


    }
    if(flag==0)
    cout<<"YES"<<endl<<count<<" ";
    if(flag==1)
        cout<<"NO"<<endl;

	// Write your code here
}
