#include <bits/stdc++.h>

using namespace std;

int a[200002];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    
    cin >> n >> k;
    
    for(int i=0;i<n;i++)
        cin >> a[i];
    
    unordered_map<long long, int> prefixCnt;
    long long sum = 0;
    long long result = 0;
    prefixCnt[0] = 1;
    
    for (int i = 0; i < n; i++) 
    {
        sum += a[i];
        result += prefixCnt[sum - k];
        prefixCnt[sum]++;
    }
    
    cout << result;
}
