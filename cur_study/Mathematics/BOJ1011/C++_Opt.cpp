#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int x, y;
        cin >> x >> y;

        int d = y - x;
        int k = sqrt(d);

        int result;
        
        if (d == k * k)
            result = 2 * k - 1;
            
        else if (d <= k * k + k)
            result = 2 * k;
            
        else
            result = 2 * k + 1;

        cout << result << '\n';
    }
}
