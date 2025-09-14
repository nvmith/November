#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            bool i_more = false, j_more = false;
            for(int c=0; c<m; c++)
            {
                if (a[i][c] == 1 && a[j][c] == 0) i_more = true;
                if (a[i][c] == 0 && a[j][c] == 1) j_more = true;
            }
            if(i_more && j_more)
            {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
}
