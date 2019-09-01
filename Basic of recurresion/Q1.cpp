#include<iostream>
using namespace std;

int power(int x, int n) {
    
    if(n==0)
        return 1;
    
     int po=power(x,n-1);
    po=po*x;
    return po;
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

}

int main(){
    int x, n;
    cin >> x >> n;
  
    cout << power(x, n) << endl;
}



