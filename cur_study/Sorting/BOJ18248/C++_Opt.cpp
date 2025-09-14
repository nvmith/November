#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> bell(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> bell[i][j];

    if(n == 1 || m == 1)
    {
        cout << "YES";
        return 0;
    }

    sort(bell.begin(), bell.end(), [&](vector<int>& a, vector<int>& b) 
    {
        for(int c=0; c<m; c++) 
        {
            if (a[c] != b[c]) 
                return a[c] > b[c];
        }
        return false;
    });

    for(int c=0; c<m; c++)
    {
        for(int i=1; i<n; i++)
        {
            if (bell[i-1][c] < bell[i][c])
            {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
}
