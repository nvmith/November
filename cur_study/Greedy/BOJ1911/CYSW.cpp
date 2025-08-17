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

    vector<pair<int,int>> v(n);
    
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    sort(v.begin(), v.end());

    ll ans=0;
    ll cur=0;

    for(int i=0; i<n; i++)
    {
        if (cur < v[i].first) cur = v[i].first;
        if (cur < v[i].second)
        {
            ll remain = v[i].second-cur;
            ll need = remain / L;
            if (remain % L != 0) need += 1;

            ans += need;
            cur += need * L;
        }
    }

    cout << ans;
}
