#include <iostream>
#include "Solution.h"
using namespace std;
bool chek(int n,int i)
{

    if(n&1<<i)
        return true;
    else
        return false;

}

int returnFirstSetBit(int n){

    for(int i=0;i<n;i++)
    {

        if(chek(n,i))
        {
            return (n & (1<<i) );

        }

    }

    //anotehr approch is n=n&(-1*n);
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

}



int main() {
	int n;

	cin >> n;

	cout<< returnFirstSetBit(n) <<endl;

	return 0;
}

