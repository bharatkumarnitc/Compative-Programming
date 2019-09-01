#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
    int T;
    int x;
    int y;
};

bool comp(struct node i1, struct node i2)
{
    if(i1.T == i2.T)
    {
        if(i1.y == i2.y)
        {
            return i1.x < i2.x;
        }
        return i1.y > i2.y;
    }
    return i1.T < i2.T;
}

int main() {
    int n, x, y, t;
    ll d;
    cin >> n >> d;
    struct node *input = new node[n];
    for(int i= 0;i<n;i++)
    {
        cin >> input[i].T >> input[i].x >> input[i].y;
    }
    sort(input, input+n, comp);
    ll area = 0;
    ll speed = 0, cost = 0, last = input[0].T;
    for(int i = 0;i<n;i++)
    {
        ll temp = speed*1LL*(input[i].T-last);
        area += temp;
        if(area >= d)
            break;
        if(input[i].y > speed)
        {
            speed = input[i].y;
            cost += input[i].x;
        }
        last = input[i].T;

    }
    cout << cost << endl;
}
