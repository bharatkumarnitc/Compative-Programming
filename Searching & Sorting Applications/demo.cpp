#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      set<int >input;
        int n,k;
        cin>>n>>k;
        while(n--)
        {
            int num;
            cin>>num;
            input.insert(num);
        }

       set<int> :: iterator itr=input.begin();
       int count=0;
      while(itr != input.end() && input.size()>=k)
      {
          int a=*itr;
          itr++;
          int b=*itr;
         if(a==b-1)
         {
             //cout<<*itr;
             input.insert(a-1);
             count++;
         }
        //itr++;
      }

   cout<<count;
    }


    return 0;
}
