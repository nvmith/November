#include <bits/stdc++.h>

using namespace std;

int sums[202][202];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    
    cin >> n >> m;
    
    for (int i=1; i<=n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int tmp;
            cin >> tmp;
            sums[i][j] = sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+tmp;
        }
    }
    
    int maxSum = INT_MIN;
    
    for (int x1=1; x1<=n; x1++)
    {
        for (int y1=1; y1<=m; y1++)
        {
            for (int x2=x1; x2<=n; x2++)
            {
                for (int y2=y1; y2<=m; y2++)
                {
                    int sum = sums[x2][y2]-sums[x1-1][y2]-sums[x2][y1-1]+sums[x1-1][y1-1];
                    maxSum = max(maxSum, sum);
                }
            }
        }
    }
    
    cout << maxSum;
}
