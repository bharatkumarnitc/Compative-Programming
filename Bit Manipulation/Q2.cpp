#include <iostream>
#include "Solution.h"
int turnOffIthBit(int n, int i)
{

    return (n & ~(1<<i));
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

}


int main() {
	int n, i;

	cin >> n >> i;

	cout<< turnOffIthBit(n, i) <<endl;

	return 0;
}

