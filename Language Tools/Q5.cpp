#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
	getline(cin,str);
    map<string,int>obj1;
	vector<string> obj;
	string word = "";
    int rep=0;
   for (auto x : str) 
   { 
       if (x == ' ') 
       { 
           obj1[word]++;
           
           word = ""; 
       } 
       else
       { 
           word = word + x; 
       } 
   }  
   obj1[word]++;
   
   for (auto& x: obj1) {
   	
   	if(x.second>1)
    {  rep=1;
        std::cout << x.first << " " << x.second <<endl;
        
    }
    
}
    if(rep==0)
        cout<<"-1"<<endl;
   
	return 0;
}

