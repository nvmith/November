#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll L;
    cin >> n >> L;

    vector<pair<ll,ll>> v(n);
    for (int i = 0; i < n; i++) 
    {
        ll a, b; cin >> a >> b;
        v[i] = {a, b};
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    ll cur = 0;

    for (int i = 0; i < n; i++) 
    {
        ll a = v[i].first, b = v[i].second;
        cur = max(cur, a);
        if (cur < b) 
        {
            ll need = (b - cur + L - 1) / L;
            ans += need;
            cur += need * L;
        }
    }

    cout << ans;
}
