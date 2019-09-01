long long staircase(int n)
{
   long long int res[n + 1];
    res[0] = 1;
    res[1] = 1;
    res[2] = 2;
    for (int i = 3; i <= n; i++)
        res[i] = res[i-1] + res[i-2]
                          + res[i-3];

    return res[n];
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */


}
#include<iostream>
using namespace std;
#include "Solution.h"

int main(){

  int n;
  cin >> n ;
  cout << staircase(n) << endl;

}


