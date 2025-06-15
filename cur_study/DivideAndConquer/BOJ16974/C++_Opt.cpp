#include <bits/stdc++.h>

using namespace std;
using ll = long long;


ll len[51];
ll patty[51];

ll pattyCnt(int level, ll x)
{
    if (level == 0) return (x >= 1 ? 1 : 0);
    if (x == 1) return 0;
    else if (x <= 1 + len[level - 1]) return pattyCnt(level - 1, x - 1);
    else if (x == len[level - 1] + 2) return patty[level - 1] + 1;
    else return patty[level - 1] + 1 + pattyCnt(level - 1, x - 2 - len[level - 1]);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, x;
    cin >> n >> x;
    len[0] = patty[0] = 1;
    for (int i = 1; i <= n; i++) 
    {
        len[i] = len[i-1]*2+3;
        patty[i] = patty[i-1]*2+1;
    }
    cout << pattyCnt(n,x);
}
