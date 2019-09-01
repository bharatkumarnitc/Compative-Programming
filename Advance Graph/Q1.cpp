#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void dfs(vector<int>*edges, int start, unordered_set<int>*component, bool *visited)
{
    visited[start]=true;
    component->insert(start);
    for(int i=0;i<edges[start].size();i++)
    {
        int next=edges[start][i];
        if(!visited[next])
        {
            dfs(edges,next,component,visited);
        }
    }
}


unordered_set<unordered_set<int>*>* getcompo(int n, vector<int>*edges)
{
    bool visited[n+1];
    for(int i=0;i<=n;i++)
    visited[i]=false;
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            unordered_set<int>*component = new unordered_set<int>();
            dfs(edges,i,component,visited);
            output->insert(component);
        }
    }
    return output;
}

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int p[n],q[n];
        for(int i=0;i<n;i++)
            cin>>p[i];
        for(int i=0;i<n;i++)
            cin>>q[i];
        vector<int>edges[n+1];
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        unordered_set<unordered_set<int>*>*components = getcompo(n, edges);
        unordered_set<unordered_set<int>*>::iterator it=components->begin();

        bool flag=false;

        while (it != components->end())
        {
		    unordered_set<int>* component = *it;
		    unordered_set<int>::iterator it2 = component->begin();
		    unordered_set<int>P;
		    unordered_set<int>Q;

		    while (it2 != component->end())
            {
			    P.insert(p[*it2-1]);
			    Q.insert(q[*it2-1]);
			    it2++;
		    }

		    unordered_set<int>::iterator it3 = P.begin();
		    unordered_set<int>::iterator it4 = Q.begin();

		    while(it3 != P.end() && !flag)
		    {
		        if(Q.find(*it3)==Q.end())
		        {
		            flag=true;

		        }

		        it3++;
		    }
		    if(flag)
		    break;
		    delete component;
		    it++;
	    }
        if(!flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
	return 0;
}
