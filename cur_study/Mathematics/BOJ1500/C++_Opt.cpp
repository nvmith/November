#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll s, k;
    cin >> s >> k;

    ll a = s/k, r = s%k;
    ll result=1;

    for (int i=0; i<k; i++)
    {
        if (r>0)
        {
            result *= (a + 1);
            r--;
        }
        else
            result *= a;
    }

    cout << result;
}
