#include <bits/stdc++.h>
using namespace std;

int s[200002], p[200002];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int total_time = 24 * n;

    for (int i = 0; i < m; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> p[i];

    priority_queue<pair<int, int>> pq;
    
    for (int i = 0; i < m; i++) 
    {
        int gain = min(p[i], 100 - s[i]);
        if (gain > 0)
            pq.push({gain, i});
    }

    while (total_time-- && !pq.empty()) 
    {
        auto [gain, i] = pq.top(); pq.pop();
        s[i] += gain;

        int new_gain = min(p[i], 100 - s[i]);
        if (new_gain > 0)
            pq.push({new_gain, i});
    }

    int result = accumulate(s, s + m, 0);
    cout << result;
}
