#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    int d;
    cin>>d;
    int arr[d]={0};
    arr[0]=1;
    n=n-1;
    int fill=9;
    int j=1;
    for(int i=d-1;i>=1;i--)
    {

        if(j==1)
        {
           j++;
            if(n<=fill)
                arr[i]=n;

            else
            {
                arr[i]=fill;
            }
        }
        else
        {
           n=n-fill;

            if(n>=fill)
                arr[i]=fill;
             else if(n==0 || n<0)
            {
                n=0;
                fill=0;
                arr[i]=0;
            }
            else if(n<=fill)
                arr[i]=n;



        }

        }


/*
string findSmallest(int m, int s)
{
    int res[m];
    s -= 1;
    for (int i=m-1; i>0; i--)
        {
            if (s > 9)
            {
                res[i] = 9;
                 s -= 9;
                 }
                 else
                    {
                    res[i] = s;
                    s = 0;
                    }
                    }
                    res[0] = s + 1;
                    string e = "";

                    for (int i=0; i<m; i++)
                        e = e + char('0'+res[i]);
                    return e;
                    }

  */
    for(int i=0;i<d;i++)
        cout<<arr[i];

}
