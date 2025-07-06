#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    int t = 24 * n;
    int score = 0;

    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < m; ++i)
    {
        if (a[i] == 100)
        {
            score += 100;
        }
        else
        {
            pq.push({b[i], a[i]});
        }
    }

    while (t > 0 && !pq.empty())
    {
        auto [gain, current_score] = pq.top(); pq.pop();

        int remain = 100 - current_score;
        int used_t = remain / gain;

        if (t < used_t)
            used_t = t;

        t -= used_t;
        int now_score = current_score + used_t * gain;

        if (now_score < 100)
        {
            pq.push({100 - now_score, now_score});
        }
        else
        {
            score += 100;
        }
    }

    while (!pq.empty())
    {
        score += pq.top().second;
        pq.pop();
    }

    cout << score << '\n';
}
