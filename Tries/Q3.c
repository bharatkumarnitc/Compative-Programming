#include<bits/stdc++.h>
using namespace std;
class trieNode
{
public:
    trieNode ** children;
    int weight;
    trieNode()
    {

        children=new trieNode*[26];
        for(int i=0;i<26;i++)
        children[i]=NULL;
        weight=0;
    }



};

void insert(string s,int weight,trieNode *root)
{

    trieNode *child;
    int index=s[0]-'a';
   if(root->children[index])
   {
    child=root->children[index];



   }
   else{
    child=new trieNode();
    root->children[index]=child;
   }

    if(root->weight<weight)
        root->weight=weight;


    insert(s.substr(1),weight,child);
}


int searchBest(string s,trieNode *root)
{
    int bestweight=-1;
    trieNode *current=root;
    for(int i=0;i<s.length();i++)
    {
        int index=s[i]-'a';

        trieNode *child=current->children[index];
        if(child)
        {
            current=child;
            bestweight=child->weight;

        }
        else
            return -1;






    }
}

    int main()
    {
        trieNode *root=new trieNode();
        int n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            int weight;
            cin>>weight;
            insert(s,weight,root);



        }

        for(int i=0;i<q;i++)
        {

            string pre;
            cin>>pre;
            cout<<searchBest(pre,root);
        }

        return 0;

}
