#include <bits/stdc++.h>

using namespace std;

int arr[10002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    int low, high;
    low = 0; high = 0;
    
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int budget;
        cin >> budget;
        arr[i] = budget;
        high = max(high, budget);
    }
    cin >> m;
    
    int ans = 0;

    while (low <= high) 
    {
        int mid = (low + high) / 2;
        int sum = 0;
        
        for (int i=0;i<n;i++)
            sum += min(arr[i], mid);

        if (sum <= m)
        {
            ans = mid;
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }
    
    cout << ans;
}
