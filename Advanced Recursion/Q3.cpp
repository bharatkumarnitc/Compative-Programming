#include <iostream>
using namespace std;
void merge(int A[],int left,int mid,int right){

	int i=left,j=mid,k=0;
    int temp[right-left+1];

    while(i<mid && j<=right)
    {
        if(A[i]<=A[j])
        {
          temp[k]=A[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=A[j];
            j++;
            k++;
        }

    }

    while(i<mid)
    {
        temp[k]=A[i];
            i++;
            k++;

    }
    while(j<=right)
    {

         temp[k]=A[j];
            j++;
            k++;

    }

    for(int i=left,k=0;i<=right;i++, k++)
        A[i]=temp[k];


}
void merge_sort(int A[],int left,int right){

	long long count = 0;
	if(right > left){
		int mid = (left + right)/2;

		merge_sort(A,left,mid);
		merge_sort(A,mid+1,right);
		merge(A,left,mid+1,right);


	}


}


void mergeSort(int input[], int size)
{
  merge_sort(input,0,size-1);
	// Write your code here

}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
