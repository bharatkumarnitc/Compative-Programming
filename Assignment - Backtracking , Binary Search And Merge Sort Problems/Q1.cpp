#include<iostream>
using namespace std;

int powerof(int x,int n)
{

    if(n==0)
        return 1;
    int num=powerof(x,n-1);
    num=num*x;

    return num;
}

int main() {
       int x,n;
        cin>>x>>n;


    cout<<powerof(x,n);
	// Write your code here

}
