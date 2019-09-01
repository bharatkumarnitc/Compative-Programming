#include<bits/stdc++.h>
using namespace std;
/*
int Knapsnack (int *weight,int *value,int n,int maxweight)
{

    if(n<0)
        return 0;

    if(weight[n-1]<=maxweight)
    {
        int value1=Knapsnack(weight,value,n-1,(maxweight-weight[n-1]))+value[n-1];
        int value2=Knapsnack(weight,value,n-1,maxweight);
        return max(value1,value2);

    }
    if(weight[n-1]>maxweight)

        return Knapsnack(weight,value,n-1,maxweight);



}

*/
void knapsack(int* weights, int* values, int n, int maxWeight)
{

   int** dp = new int*[2];
	for(int i=0;i<=n;i++)
		dp[i] = new int[maxWeight+1];

	for(int i=0;i<=maxWeight;i++)
    {
		dp[0][i] = 0;
        dp[1][i] = 0;
	}

	for(int i = 0; i <= n; i++)
    {
		int w = 0;
        if(i%2)
        {
            while(++w <= maxWeight)
            {
                if(weights[i] <= w)
                    dp[1][w] = max(dp[0][w], dp[0][w-weights[i]] + values[i]);
                else
                    dp[1][w] = dp[0][w];
            }
        }
        else
        {
            while(++w <= maxWeight)
            {
                if(weights[i] <= w)
                    dp[0][w] = max(dp[1][w], dp[1][w-weights[i]] + values[i]);
                else
                    dp[0][w] = dp[1][w];
            }
        }
	}

	int ans = dp[!n%2][maxWeight];

	int maxfun=ans;
	int minmoney=0;
	for(int i=0;i<=maxWeight;i++)
	{
		if(dp[n][i]==maxfun)
		{
			minmoney=i;
			break;
		}
	}
	cout<<minmoney<<" "<<ans<<endl;

	//return ans;
}
int main()
{
    int n;
    cin>>n;
    int *weight=new int[n];
    int *value=new int[n];
    for(int i=0;i<n;i++)
        cin>>weight[i];
    for(int j=0;j<n;j++)
        cin>>value[j];

    int maxweight;
    cin>>maxweight;

    //cout<<Knapsnack(weight,value,n,maxweight)<<" ";
    //cout<<sum;

    knapsack(weight,value,n,maxweight);

    delete[] weight;
    delete[] value;
    return 0;
}
