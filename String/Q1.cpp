#include <iostream>
using namespace std;
int * getLPS(char pattern[])
{    int i;
    for(i=0;pattern[i]!='\0';i++);
  int lenpattr=i;
  int* arr=new int[lenpattr];
  arr[0]=0;
    i=1;
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





int  KMP(char text[],char pattrn[])
{
	int i,j;
    for(i=0;text[i]!='\0';i++);
	int lentext=i;
        for(j=0;pattrn[j]!='\0';j++);
	int lenpattern=j;
	i=0;
	j=0;
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
		  	    pos=i;	
		  		break;
			  }
		
	}
	
			if(j==lenpattern)
		      return pos-lenpattern;
		 return -1;		
}

int findString(char S[], char T[]) {
    // Write your code here
  
     return KMP(S,T);
}


int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}

