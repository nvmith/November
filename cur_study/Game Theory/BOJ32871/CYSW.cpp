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
        
        if(n == 1 || m == 1)
        {
            cout << "YES" << '\n';
            continue;
        }
        
        if(abs(n-m) % 2 == 0)
            cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}
