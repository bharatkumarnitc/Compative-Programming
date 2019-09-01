#include<iostream>
//#include "Solution.h"
using namespace std;

int Partation(int a[],int p,int r)
{

    int x=a[r],temp,j;
    int i;
    i=p-1;

    for(j=p;j<=r-1;j++)
    {

        if(a[j]<=x)
        {
            i=i+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
      temp=a[i+1];
      a[i+1]=x;
      a[r]=temp;
    return i+1;
}


void Quick_Sort(int input[],int low,int heigh)
{

  int pivot;
    if(low<heigh)
    {

        pivot=Partation(input,low,heigh);
        Quick_Sort(input,low,pivot-1);
        Quick_Sort(input,pivot+1,heigh);


    }


}



void quickSort(int input[], int size)
{



    Quick_Sort(input,0,size-1);

}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

}


