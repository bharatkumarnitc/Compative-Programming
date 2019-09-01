#include<bits/stdc++.h>
using namespace std;
struct node
{
	int maximum;
	int smaximum;
};
void buildtree(int *arr,node *tree,int st,int end,int treeindex)
{
	if(st==end)
	{
		tree[treeindex].maximum=arr[st];
		tree[treeindex].smaximum=INT_MIN;
		return;
	}
	int mid=(st+end)/2;
	
	buildtree(arr,tree,st,mid,2*treeindex);
	buildtree(arr,tree,mid+1,end,(2*treeindex)+1);
	
	node left=tree[2*treeindex];
	node right=tree[(2*treeindex)+1];
	tree[treeindex].maximum=max(left.maximum,right.maximum);
	tree[treeindex].smaximum=min(max(left.maximum,right.smaximum),max(left.smaximum,right.maximum));
	
	
}


node query(node *tree,int st,int end,int treeindex,int left,int right)
{
	
  if(st>right || end<left )
  {
  	node demo;
  	demo.maximum=0;
  	demo.smaximum=INT_MIN;
  	return demo;
  }


  if(st>=left && end<=right)
  {
  	return tree[treeindex];
  	
	  }
 int mid=(st+end)/2;	  
 	node le=query(tree,st,mid,2*treeindex,left,right); 	
	node ri=query(tree,mid+1,end,(2*treeindex)+1,left,right);	
	node ans;
	ans.maximum=max(le.maximum,ri.maximum);
	ans.smaximum=min(max(le.maximum,ri.smaximum),max(le.smaximum,ri.maximum));
	return ans;  	
}
void updatetree(int *arr,node *buildarraytree,int st,int end,int tree,int pos,int value)
{
	
	if(st==end)
	{
		
		arr[pos]=value;
		buildarraytree[tree].maximum=value;
		buildarraytree[tree].smaximum=INT_MIN;
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
	

	node left=buildarraytree[2*tree];
	node right=buildarraytree[(2*tree)+1];
	buildarraytree[tree].maximum=max(left.maximum,right.maximum);
	buildarraytree[tree].smaximum=min(max(left.maximum,right.smaximum),max(left.smaximum,right.maximum));
	
	
}
int main() {
    
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    node *tree=new node[3*n];
    buildtree(arr,tree,0,n-1,1);
    int q;
    cin>>q;
   while(q--)
  {
      char ch;
      cin>>ch;
      int index,value;
      cin>>index>>value;
      switch(ch)
     {
         node t;  	
      	case 'Q': t=query(tree,0,n-1,1,index-1,value-1);
		  cout<<t.maximum+t.smaximum<<endl;
    		     break;
      	case 'U':
     		     updatetree(arr,tree,0,n-1,1,index-1,value);
       		      break;
		}
       
       
       
  }

	// Write your code here
}
