#include<bits/stdc++.h>
using namespace std;


//recursive
int Edit_Distance(string s1,string s2)
{
    if(s1.length()==0|| s2.length()==0)
        return 0;
    if(s1[0]==s2[0])
        return Edit_Distance(s1.substr(1),s2.substr(1));

      int op1=1+Edit_Distance(s1.substr(1),s2);   //remove
      int op2=1+Edit_Distance(s1.substr(1),s2.substr(1));  //substitue
      int op3=1+Edit_Distance(s1,s2.substr(1)) ; //insert
    return min(op1,min(op2,op3));

}

//Using Dp
int editDistance(string s1, string s2)
{
    int m=s1.length();
    int n=s2.length();
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++)
    dp[i]=new int[n+1];
      for(int i = 0; i < m+1; i++)
	{
		for(int j = 0; j < n+1; j++)
		{
			if(i == 0)
			{
				dp[i][j] = j;
			}
			else if(j == 0)
			{
				dp[i][j] = i;
			}
			else if(s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
			}
       }

}
     return dp[m][n];
}






int main()
{

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << Edit_Distance(s1,s2) << endl;
  cout<<editDistance(s1,s2)<<endl;



    return 0;
}
