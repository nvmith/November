#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        deque<int> dq;
        for (int i=0; i<n; i++)
        {
            if (i%2 == 0) 
                dq.push_back(a[i]);
            else 
                dq.push_front(a[i]);
        }

        int ans=0;
        for (int i= 0; i<n; i++)
        {
            int j = (i+1) % n;
            ans = max(ans, abs(dq[i]-dq[j]));
        }
        cout << ans << "\n";
    }
}
