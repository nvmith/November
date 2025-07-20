#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    
    cin >> n >> k;
    
    ll sum = 0, result = 0;
    
    unordered_map<ll, int> prefixCnt;
    prefixCnt[0] = 1;
    
    for (int i = 0; i < n; i++) 
    {
        int input;
        cin >> input;
        sum += input;
        result += prefixCnt[sum - k];
        prefixCnt[sum]++;
    }
    
    cout << result;
}
