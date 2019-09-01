#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f 
struct node
{
	int maxprefixsum;
	int maxsufixsum;
	int totalsum;
	int maxsubarrrysum;
    node()
    {
    	maxprefixsum=maxsufixsum=totalsum=maxsubarrrysum=-inf;
	}

	
};

node merge(node left,node right)
{
	//cout<<"mergecall";
node parent;
parent.maxprefixsum=max(left.maxprefixsum,left.totalsum+right.maxprefixsum);
parent.maxsufixsum=max(right.maxsufixsum,right.totalsum+left.maxsufixsum);
parent.totalsum=(left.totalsum)+(right.totalsum);
parent.maxsubarrrysum = max(left.maxsubarrrysum,max(right.maxsubarrrysum,left.maxsufixsum + right.maxprefixsum)); 
	return parent;
}
void buildtree(int *arr,node *tree ,int st,int end,int treeindex)
{

if(st==end)
{
	tree[treeindex].maxprefixsum=arr[st];
	tree[treeindex].maxsufixsum=arr[st];
	tree[treeindex].totalsum=arr[st];
	tree[treeindex].maxsubarrrysum=arr[st];
	return;
	}	
	
  int mid=(st+end)/2;
  //cout<<"buildtree";
  buildtree(arr,tree,st,mid,2*treeindex);
  buildtree(arr,tree,mid+1,end,(2*treeindex)+1);
  
 tree[treeindex]=merge(tree[2*treeindex],tree[(2*treeindex)+1]);	
	
	
}
node query(node *tree,int st,int end,int treeindex,int left,int right)
{
	
	if(st>right || end<left)
	{
		node nullnode;
		return nullnode;
	}
	
	if(st>=left && end<=right)
	return tree[treeindex];
	int mid=(st+end)/2;
	
	node le=query(tree,st,mid,2*treeindex,left,right);
	node ri=query(tree,mid+1,end,(2*treeindex)+1,left,right);
	
	node ans=merge(le,ri);
	
	
	return ans;	
		
		
}
int main()
{
	
int n;
cin>>n;
int *arr=new int[n];
node *tree =new  node[4*n];
for(int i=0;i<n;i++)
cin>>arr[i];	
buildtree(arr,tree,0,n-1,1);
int q;
cin>>q;
while(q--)
{
	int st,end;
	cin>>st>>end;
	node t=query(tree,0,n-1,1,st-1,end-1);
	cout<<t.maxsubarrrysum<<endl;
	
	
	
	}	
	
	
}
