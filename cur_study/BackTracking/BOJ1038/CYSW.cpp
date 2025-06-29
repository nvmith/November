#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> v;

void func(int limit, string cur)
{
    v.push_back(stoll(cur));

    for (int i = 0; i < limit; i++)
        func(i, cur + to_string(i));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < 10; i++)
        func(i, to_string(i));

    sort(v.begin(), v.end());

    if (n >= v.size()) cout << -1;
    else cout << v[n];
}
