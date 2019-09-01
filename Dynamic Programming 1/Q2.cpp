#include<iostream>
using namespace std;

int longestBitonicSubarray(int input[],int size)
{

    int inc[size];
    int dec[size];
    inc[0]=1;
    dec[size-1]=1;
    for(int i=1;i<size;i++)
    {
        inc[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(input[i]>input[j])
            {
               int possible=inc[j]+1;
               if(possible>inc[i])
                    inc[i]=possible;

            }

        }
    }

    for(int i=size-2;i>=0;i--)
    {
        dec[i]=1;
        for(int j=i+1;j<size;j++)
        {

            if(input[i]>input[j])
            {
                int possible=dec[j]+1;
                if(possible>dec[i])
                    dec[i]=possible;
            }
        }
    }
    int max=inc[0]+dec[0]-1;
    for (int i = 1; i < size; i++)
     if (inc[i] + dec[i] - 1 > max)
         max = inc[i] + dec[i] - 1;
         return max;
}



int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}
