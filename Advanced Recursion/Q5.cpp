#include<bits/stdc++.h>
using namespace std;
#include <cstring>
using namespace std;
string helper(int n){
   if(n==2){
     return "abc";
   }else if(n==3){
     return "def";
   }else if(n==4){
     return "ghi";
   }else if(n==5){
     return "jkl";
   }else if(n==6){
     return "mno";
   }else if(n==7){
     return "pqrs";
   }else if(n==8){
     return "tuv";
   }else if(n==9){
     return "wxyz";
   }
}
int keypad(int num, string *output)
{
    //cout<<"jello";
  if(num==0)
  {
    output[0]="";
    return 1;
  }
  string *smalloutput=new string[100000];
  int ss=keypad(num/10,smalloutput);
  int z=num%10;
  string small=helper(z);
  int count=small.size();
  int k=0;
  for(int i=0;i<count;i++)
  {

    for(int j=0;j<ss;j++){
      output[k++]=smalloutput[j]+small[i];
    }
  }
  return k;
}


int main(){
    int num;
    cin >> num;

    string *output=new string[10000];
    int counts = keypad(num, output);
    for(int i = 0; i < counts && i < 10000; i++)
        {
        cout << output[i] << endl;
    }
    return 0;
}
