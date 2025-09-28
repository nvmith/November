#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll comb(int n,int k)
{
    ll res=1;
    for(int i=1;i<=k;i++)
        res = res*(n-i+1)/i;
    return res;
}

int main()
{
    int N, K;
    cin >> N >> K;
    ll ans = comb(N,K) * (1LL<<(K-1));
    cout << ans; // 빌어먹을 큰 수로 나눠야함
}
