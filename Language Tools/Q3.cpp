#include<bits/stdc++.h>
using namespace std;

char getChar(int i)
{
    return((char)(i+97));
}

void printPALINDROME(string s)
{
    map<char,vector<int>> indexMAP;
    for(int i=0;i<s.length();i++)
    {
        indexMAP[s[i]].push_back(i);
    }
    
   int oddFREQUENCYcount=0;
   for(int i=0;i<26;i++)
   {
       if(indexMAP[getChar(i)].size()%2!=0)
       oddFREQUENCYcount++;
   }
   if(oddFREQUENCYcount>=2)
   {
       cout<<"-1";
       return;
   }
   
   int ans[s.length()];
   int start=0;
   int end=s.length()-1;
   
   for(int i=0;i<26;i++)
   {
       for(int j=0;j<indexMAP[getChar(i)].size();j+=2)
       {
           if(indexMAP[getChar(i)].size()-j==1)
           {
               ans[s.length()/2]=indexMAP[getChar(i)][j];
               continue;
           }
           ans[start]=indexMAP[getChar(i)][j];
           ans[end]=indexMAP[getChar(i)][j+1];
           start++;
           end--;
       }
   }
   
   for(int i=0;i<s.length();i++)
   cout<<ans[i]+1<<" ";
}

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string s;
        cin>>s;
         printPALINDROME(s);
         cout<<endl;
    }
    
    return 0;
}
