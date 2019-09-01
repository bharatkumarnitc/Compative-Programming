#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int>&a,const pair<int,int>&b)
{
  return a.first<b.first;
}

  
int main() {

	int n;
  cin>>n;
  int start[n];
  int end[n];
  int m=n;
 for(int i=0;i<n;i++)
 {
    cin>>start[i];
  }
  for(int i=0;i<m;i++)
  {
	cin>>end[i];
  }
  vector<pair<int,int>>res;
  for(int i=0;i<n;i++)
  {
    res.push_back(make_pair(start[i],end[i]));
  }
    // make a pair array or vector for start and input time
    // sort this on the basis of start time
    //
  sort(res.begin(),res.end(),cmp);
	multiset<int>mul;
  /*for(int i=0;i<res.size();i++)
  {
    cout<<res[i].first<<" "<<res[i].second<<endl;
  }*/
  int ans=0;
  mul.insert(res[0].second);
  for (int j = 1; j < n; j++) 
    { 
    	ans=max(ans,(int)mul.size());
    	cout<<ans<<" ";
    	auto it=*mul.begin();
    	while(!mul.empty() and it<=res[j].first)
        {   cout<<endl;
            cout<<it<<" "<<res[j].first<<endl;
          mul.erase(mul.find(it));
          if(!mul.empty())
          	 it=*mul.begin();
         }
          
        mul.insert(res[j].second);
    
    }
  ans=max(ans,(int)mul.size());
  cout<<ans<<endl;
}
