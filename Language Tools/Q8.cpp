#include<bits/stdc++.h>
using namespace std;
struct stu
{
    string name;
    int marks;
    int rno;
    
};
bool sortbysec(const stu &a,const stu &b) 
{ 
    if(a.marks!=b.marks)
    {
        return (a.marks > b.marks);
    }
    
    else
    {
        return a.rno < b.rno;
    }
} 
int main()
{
   long int t;
    cin>>t;
   vector<stu>obj;
    int i=1;
    while(i<=t)
    {
        
        string s;
        cin>>s;
        int m1,m2,m3;
        cin>>m1>>m2>>m3;
        int sum=m1+m2+m3;
        stu s1;
        s1.name=s;
        s1.marks=sum;
        s1.rno=i;
        obj.push_back(s1);
        i++;
        
    }
    int j=1;
    sort(obj.begin(),obj.end(),sortbysec);
    for (int i=0; i<obj.size(); i++) 
    { 
        cout<<j<<" "<< obj[i].name << endl; 
        j++;
    } 
}
