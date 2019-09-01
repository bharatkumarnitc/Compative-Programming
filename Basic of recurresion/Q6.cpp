#include<iostream>
using namespace std;
int firstIndex(int input[], int size, int x) {
    
   int ans;
    if(size==0)
        return -1;
    if(input[0] == x)
        return 0;
    
    ans=firstIndex(input+1,size-1,x);
    if(ans == -1)
        return -1;
    else
        return ans+1;
    
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
    
    cout << firstIndex(input, n, x) << endl;

}



