#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m,k;
    
    cin >> n >> m >> k;
    
    vector<pair<int,int>> v(n);
    
    for(int i=0; i<n; i++)
    {
        int tmp, ttmp;
        cin >> tmp >> ttmp;
        v[i] = {tmp, ttmp};
    }
    
    sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b){
        return a.second > b.second;
    });
    
    ll result = 0;
    
    for(int i=0; i<k; i++)
        result += v[i].first;
    
    sort(v.begin()+k, v.end(), [](pair<int,int>& a, pair<int,int>& b){
         return a.first > b.first;
     });
    
    int take = min(m, n-k);
    for (int i=k; i<k+take; i++)
        result += v[i].first;
    
    cout << result;
}
