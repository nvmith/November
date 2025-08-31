#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int L, U;
    ull sum = 0, multi = 1;
    cin >> L >> U;
    if (L == 1)
    {
        sum++;
        L++;
    }
    if (U != 1 && L == 2)
    {
        sum++;
        L++;
    }
    cout << (sum & 1 ? "H" : "A") << "\n";
    for (int i = 3; i <= U; i++)
    {
        if (i & 1)
        {
            multi = (multi * 26) % 1000000007;
        }
        if (i >= L)
        {
            sum = (sum + multi) % 1000000007;
        }
    }
    cout << sum;
}
