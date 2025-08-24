#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    
    cin >> t;
    
    while(t--)
    {
        ll n, m;
        
        cin >> n >> m;
        
        if(n == 1 || m == 1 || (n-m) % 2 != 0)
            cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
