#include<iostream>	
using namespace std;
int sum(int input[], int n) {
    
 static int num=0;
    if(n==0)
        return 0;
    
    sum(input,n-1);
    num+=input[n-1];
    return num;
    
    
    
    
}
    

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    cout << sum(input, n) << endl;
}



