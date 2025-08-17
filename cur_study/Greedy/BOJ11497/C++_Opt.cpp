#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    if (!(cin >> t)) return 0;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int ans = 0;
        for (int i = 0; i + 2 < n; i++)
        {
            int diff = a[i + 2] - a[i];
            if (diff > ans) ans = diff;
        }

        if (n == 2)
        {
            int d = a[1] - a[0];
            if (d > ans) ans = d;
        }

        cout << ans << '\n';
    }
    return 0;
}
