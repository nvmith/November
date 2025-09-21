#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N, K;
    cin >> N >> K;

    ll n = N+K-1;
    ll k = K-1;
    
    if (k > n-k) 
        k = n-k;

    vector<ll> C(k+1, 0);
    C[0] = 1;

    for(ll i=1; i<=n; i++)
    {
        ll upto = min(i, k);
        for(ll j=upto; j>=1; j--)
        {
            C[j] += C[j-1];
            if (C[j] >= 1000000000) 
                C[j] -= 1000000000;
        }
    }

    cout << C[k];
}
