#include<bits/stdc++.h>
using namespace std;

void buildtree(int *arr,int *buildarraytree,int lo,int high,int tree)
{
	if(lo==high)
	{
		buildarraytree[tree]=arr[lo];
		return;
	}

	int mid=(lo+high)/2;
    buildtree(arr,buildarraytree,lo,mid,(2*tree));
	buildtree(arr,buildarraytree,mid+1,high,((2*tree)+1));

    buildarraytree[tree]=buildarraytree[2*tree]+buildarraytree[(2*tree)+1];

}
void updatetree(int *arr,int *buildarraytree,int st,int end,int tree,int pos,int value)
{

	if(st==end)
	{

		arr[pos]=value;
		buildarraytree[tree]=value;
        return;
	}

	int mid=(st+end)/2;


	if(pos>mid)
	{
		updatetree(arr,buildarraytree,mid+1,end,((2*tree)+1),pos,value);

	}
	else
	{
		updatetree(arr,buildarraytree,st,mid,(2*tree),pos,value);
	}

	buildarraytree[tree]=buildarraytree[2*tree]+buildarraytree[(2*tree)+1];

}

int query(int *buildarraytree,int st,int end,int tree,int left,int right)
{
//complete outside

if(st>right|| end<left)

return 0;
//complete inside

if(st>=left && end<=right)
return buildarraytree[tree];


//partially inside or outside
int mid=(st+end)/2;
int ans1=query(buildarraytree,st,mid,2*tree,left,right);
int ans2=query(buildarraytree,mid+1,end,(2*tree)+1,left,right);
return ans1+ans2;


}
int main()
{

int size;
cin>>size;
int *arr=new int[size];
for(int i=0;i<size;i++)
cin>>arr[i];
int *buildarrytree=new int[2*size];

buildtree(arr,buildarrytree,0,size-1,1);

for(int i=1;i<2*size;i++)
cout<<buildarrytree[i]<<" ";

//updatetree(arr,buildarrytree,0,size-1,1,2,10);
//	cout<<endl;
//	for(int i=1;i<2*size;i++)
//	cout<<buildarrytree[i]<<" ";
	cout<<endl;
cout<<query(buildarrytree,0,size-1,1,2,5)<<" ";

	return 0;
}
