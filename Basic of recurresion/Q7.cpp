#include<iostream>
#include "Solution.h"
using namespace std;

int lastIndex(int input[], int size, int x) {
    

    
    if(size<-1)
        return -1;
    
    if(input[size]==x)
    {
        return size;
    }    
    lastIndex(input,size-1,x);
    

  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  

  /* Don't write main().
  
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}



