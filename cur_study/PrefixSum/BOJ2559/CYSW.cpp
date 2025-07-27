#include <bits/stdc++.h>

using namespace std;

int sums[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    
    cin >> n >> k;
    
    for(int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        sums[i] = sums[i-1] + tmp;
    }
    
    int maxSum = sums[k-1];

    for (int i=1; i<=n-k; i++)
        maxSum = max(maxSum, sums[i+k-1]-sums[i-1]);
    
    cout << maxSum;
}
