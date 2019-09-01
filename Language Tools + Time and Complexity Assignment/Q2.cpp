#include <iostream>
using namespace std;
// size - size of array
// x - sum of triplets

void FindTriplet(int arr[], int n, int x) {
 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(arr[i]+arr[j]+arr[k]==x)
                {
                    int min_element=min(arr[i],min(arr[j],arr[k]));
                    int max_element=max(arr[i],max(arr[j],arr[k]));
                    int middle=x-min_element-max_element;
                    cout<<min_element<<" "<<middle<<" "<<max_element<<endl;
                }
            }
        }
    }
    
    
}


int main() {

	int size;

	int x;
	cin>>size;
	
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;

	FindTriplet(input,size,x);
		
	return 0;
}


