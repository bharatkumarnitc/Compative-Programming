#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int n,m;
    cin>>n>>m;
    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    queue<ll>q;
    int cnt=0;
    int ep=n-1;
    sort(arr,arr+n);
    while(m--){
        int idx;
        cin>>idx;
        ll ans;
        for(;cnt<idx;cnt++){
            if(ep>=0&&(q.empty()||arr[ep]>=q.front())){
                ans=arr[ep];
                ep--;
            }
            else{
                ans=q.front();
                q.pop();
            }
            q.push(ans/2);
        }
        cout<<ans<<"\n";
    }
}
