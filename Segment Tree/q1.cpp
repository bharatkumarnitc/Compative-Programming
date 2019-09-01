#include<bits/stdc++.h>
using namespace std;
void buildtree(int *arr,int *tree,int st,int end,int treeindex)
{
    
    if(st==end)
    {
        tree[treeindex]=arr[st];   
        return;
    }
    
    int mid=(st+end)/2;
    buildtree(arr,tree,st,mid,2*treeindex);
    buildtree(arr,tree,mid+1,end,(2*treeindex)+1);
    tree[treeindex]=min(tree[2*treeindex],tree[(2*treeindex)+1]);
    
}

int query(int *tree,int st,int end,int treeindex,int left,int right)
{
    if(st>right || end<left)
     return 100000007;
 
  if(st>=left && end<=right)
        return tree[treeindex];
    
    int mid=(st+end)/2;
    int le=query(tree,st,mid,2*treeindex, left,right);
    int ri=query(tree, mid+1,end,((2*treeindex)+1),left,right);
 
   if(le>ri)
       return ri;
    else
        return le;
    
    
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
	
	buildarraytree[tree]=min(buildarraytree[2*tree],buildarraytree[(2*tree)+1]);
	
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int *arr=new int[n];
    int *tree=new int[4*n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    buildtree(arr,tree,0,n-1,1);
    char ch;
    int index,value;
   
    while(q--)
    {
          cin>>ch;
          cin>>index>>value;
       switch(ch)
    {
                 
       
        case 'q': cout<<query(tree,0,n-1,1,index-1,value-1)<<endl;
                  break;
            
            
        case 'u':
                 updatetree(arr,tree,0,n-1,1,index-1,value);
                  break;
            
    }  
        
    }
   
	// Write your code here
}
