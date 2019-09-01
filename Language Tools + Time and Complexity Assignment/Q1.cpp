#include <iostream>
using namespace std;

int MissingNumber(int arr[], int size){
    
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
    }

    int n=(((size-2)*((size-2)+1)))/2;
        return (sum-n);

}

int main() {
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout << MissingNumber(input, size);	
	
	delete [] input;

	return 0;
}

