#include <bits/stdc++.h>

using namespace std;

int arr[1026][1026];

int eat(int x, int y, int size)
{
    if (size == 1)
        return arr[x][y];

    int mid = size / 2;

    int total = 0;
    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++)
            total += arr[i][j];

    int dir = total % 4;

    int dx[4] = {0, 0, mid, mid};
    int dy[4] = {0, mid, 0, mid}; 

    for (int i = 0; i < mid; i++)
        for (int j = 0; j < mid; j++)
            arr[x + dx[dir] + i][y + dy[dir] + j] = 0;

    int result = 0;
    for (int d = 0; d < 4; d++)
    {
        if (d == dir) continue;
        result += eat(x + dx[d], y + dy[d], mid);
    }

    return result;
}



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
        for (int i = 0; i < n; i++)
        {
            string st;
            cin >> st;
            for (int j = 0; j < n; j++)
                arr[i][j] = st[j] - '0';
        }

        int result = eat(0, 0, n);
        cout << result << '\n';
    }
}
