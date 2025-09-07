#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    if (!(cin >> n)) return 0;
    
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++) 
    {
        dp[i] = dp[i - 1] + 1;
        if (i >= 2) dp[i] = min(dp[i], dp[i - 2] + 1);
        if (i >= 5) dp[i] = min(dp[i], dp[i - 5] + 1);
        if (i >= 7) dp[i] = min(dp[i], dp[i - 7] + 1);
    }

    cout << dp[n];
}
