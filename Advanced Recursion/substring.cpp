#include<bits/stdc++.h>
using namespace std;

int find_substring(string input,string *output)
{
    if(input.empty())
    {
        output[0]=" ";
        return 1;
    }

    string substring=input.substr(1);
    int len=find_substring(substring,output);
    for(int i=0;i<len;i++)
    {

        output[i+len]=input[0]+output[i];

    }

    return 2*len;


}


int main()
{
    string input;
    string *output=new string[1000];
   cin>>input;

    int len=find_substring(input,output);
    for(int i=0;i<len;i++)
        cout<<output[i]<<endl;


    return 0;
}
