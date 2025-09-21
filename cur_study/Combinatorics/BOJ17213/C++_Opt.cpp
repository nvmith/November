#include <bits/stdc++.h>

using namespace std;

long long comb(int n, int k) 
{
    if (k < 0 || k > n) return 0;
    if (k > n - k) k = n - k;
    long long res = 1;
    for (int i = 1; i <= k; i++)
        res = res * (n - k + i) / i;
    return res;
}

int main() 
{
    int N, M;
    cin >> N >> M;
    
    cout << comb(M-1, N-1);
}
