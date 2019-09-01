#include<iostream>
using namespace std;

char* uniqueChar(char *str)
{


     int index = 0;
   int len;    
     for(len=0;str[len]!='\0';len++);
	 int n=len+1;
   for (int i=0; i<n; i++) 
   { 
     int j;   
     for (j=0; j<i; j++)
	 {
	 	if (str[i] == str[j]) 
           break; 
	 	
	  } 
     if (j == i) 
        str[index++] = str[i]; 
   } 
     
   return str; 
} 
int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}

