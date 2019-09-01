#include<bits/stdc++.h>
using namespace std;
int * getLPS(string pattern)
{
  int lenpattr=pattern.length();
  int* arr=new int[lenpattr];
  arr[0]=0;
  int i=1;
  int j=0;
  while(i<lenpattr)
  {
  	if(pattern[i]==pattern[j])
  	{
  		arr[i]=j+1;
  		i++;
  		j++;
  		
	  }
	  else
	  {
	  	
	  	if(j!=0)
	  	j=arr[j-1];
	  	else
	  	{	
	  		arr[i]=0;
	  		i++;
		  }
	  }
  }
	return arr;
}





int KMP(string text,string pattrn)
{
	
	int lentext=text.length();
	int lenpattern=pattrn.length();
	int i=0;
	int j=0;
	int pos=0;
	int count=0;
	int *lps=getLPS(pattrn);
	while(i<lentext && j<lenpattern)
	
	{
	  if(text[i]==pattrn[j])
	  {
	  i++;
	  j++;
	}
		  else
		  {
		  	
		  	if(j!=0)
		  	    j=lps[j-1];
		  	    else
			    i++;
			  }
			  
		  	if(j==lenpattern)
		  	{
		  	  count++;
		  	  j=0;
			  }
		
	}
	    //cout<<pos-lenpattern<<endl;
         //cout<<count;
//			if(j==lenpattern)
//		      return pos-lenpattern;
		 return count;		
}

int main()
{
	
	
string s1,s2;
getline(cin,s1);
getline(cin,s2);
//cin>>s1>>s2;

cout<<KMP(s1,s2);	
	
	
	
}
