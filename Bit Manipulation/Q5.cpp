#include <iostream>
#include "Solution.h"
using namespace std;



int clearAllBits(int n, int i){

    int mask=(1<<i)-1;
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
        n=n&mask;
    return n;

}

int main() {
	int n, i;

	cin >> n >> i;

	cout<< clearAllBits(n, i) <<endl;

	return 0;
}
