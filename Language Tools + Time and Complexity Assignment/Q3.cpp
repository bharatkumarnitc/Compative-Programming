#include <iostream>
using namespace std;

void Rotate(int arr[], int d, int size) 
{
    
    d=d%size;
    
    for(int i=0;i<d;i++)
    {
        int temp=arr[0];
      for(int i=0;i<size-1;i++)
      {
          arr[i]=arr[i+1];
      }
       arr[size-1]=temp; 
        
    }
    
    
 

}	

int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;
    
    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;

}

