#include<bits/stdc++.h>
using namespace std;
vector<int> longestSubsequence(int *arr, int n)
{
    map<int,bool> hm;
    
    //filling the map with true only for those elements which are present in the array arr
    for(int i=0;i<n;i++)
    {
        if(hm.count(arr[i]) == 0)
        {
            hm[arr[i]] = true;
        }
    }
    
    // vector ans decleartion  
    vector<int>ans;
    int maxCount=1;
    int start = arr[0];
    
    // this will check the Longest Consecutive Subsequence (LCS)
    for(int i=0;i<n;i++)
    {
        int count=0;
        int temp=arr[i];
        
        // this will loop will check for the length of the Consecutive Subsequence
        while(hm.count(temp)==1)
        {
            count++;
            temp++;
        }
        // this for max length 
        
        if(count>maxCount)
        {
            maxCount=count;
            start=arr[i];
        }
    }
    
    // pushing the first element in the array which is in variable start
    ans.push_back(start);
    maxCount--;
    // followed by filling of the next Consecutive Subsequence after Start 
    while(maxCount !=0)
    {
        start++;
        ans.push_back(start);
        maxCount--;
    }
    // finally returning the ans vector<int>
return ans;
}


int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	vector<int> output = longestSubsequence(input, n);
	for(int i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}
}

