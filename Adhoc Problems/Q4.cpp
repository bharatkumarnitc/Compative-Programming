#include<bits/stdc++.h>
using namespace std;
int main()
{

    int arr[12];
    for(int i=0;i<12;i++)
        arr[i]=i;

    int t;
    cin>>t;
    while(t--)
    {

        int i,p;
        cin>>i>>p;
//          int last;
//         int k;
//         if(i==11)
//             k=0;
//         else
//          k=i+1;

//         for(int j=1;j<=p;j++)

//         {


//                last =arr[k];

//               if(last==arr[11])
//               {
//                   k=-1;
//               }
//             k++;

//         }

//         cout<<last<<endl;

        cout<<(i+p)%12<<endl;

    }




	return 0;
}
