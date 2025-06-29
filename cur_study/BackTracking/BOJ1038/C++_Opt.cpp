#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> v;

void func(ll limit)
{
    v.push_back(limit);

    for (int i = 0; i < limit % 10; i++) func(limit*10 + i);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < 10; i++)
        func(i);

    sort(v.begin(), v.end());

    if (n >= v.size()) cout << -1;
    else cout << v[n];
}
