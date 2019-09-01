#include<bits/stdc++.h>
using namespace std;
class tree
{
	public:
	tree* left;
	tree* right;
};
void insert(int n,tree *node)
{

	tree *curr=node;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1;

		if(b==0)
		{
			if(!curr->left)
			{
				curr->left=new tree();
			}

			curr=curr->left;
		}
		else
		{
			if(!curr->right)
			{
				curr->right=new tree();
			}

			curr=curr->right;
		}
	}
}


int findmaxxorpair(tree *head,int n,int *arr)
{
	int max_xor=INT_MIN;
	for(int i=0;i<n;i++)
	{
		int value=arr[i];

		tree* curr=head;
		int curr_xor=0;
		for(int j=31;j>=0;j--)
		{
			int b=(value>>j)&1;

			if(b==0)
			{

			   if(curr->right)
			   {
			    curr_xor+=pow(2,j);
			   	curr=curr->right;
			   }

				else
				curr=curr->left;

			}

			else
			{

				if(curr->left)
				{
			    curr_xor+=pow(2,j);
				curr=curr->left;
				}

				else
				curr=curr->right;

			}
		}

		//cout<<curr_xor<<" ";
		if(curr_xor>max_xor)
		max_xor=curr_xor;


	}

	return max_xor;
}

int main()
{
	int n;
	cin>>n;
	int *input=new int[n];
	for(int i=0;i<n;i++)
	cin>>input[i];

	tree *head=new tree();
	for(int i=0;i<n;i++)
	{
		insert(input[i],head);
	}

	cout<<findmaxxorpair(head,n,input);





    delete input;
	return 0;
}
