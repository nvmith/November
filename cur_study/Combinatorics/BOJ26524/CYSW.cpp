#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long result = 1;

    for (int i=2; i<=n; i++)
        result = (result*i) % 1000000007;

    cout << result;
}
