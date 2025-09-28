#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    
    for(int i=0; i<n; i++) 
        cin >> c[i];

    int over = 100005;
    vector<int> dp(k+1, over);
    dp[0] = 0;

    for(int x : c) 
    {
        for(int s=k; s>=x; s--) 
        {
            if(dp[s-x] != over)
                dp[s] = min(dp[s], dp[s-x]+1);
        }
    }

    if(dp[k] == over)
        cout << -1;
    else 
        cout << dp[k];
}
