#include <bits/stdc++.h>

using namespace std;
 
unordered_map<string, int> mp;
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,ans=0;
    cin >> n;
    
    for(int i = 0; i < n; i++) 
    {
        string c, s;
        cin >> c >> s;
        c = c.substr(0, 2);
        if(s == c) continue;
        mp[s + c]++;
        ans += mp[c + s];
    }
 
    cout << ans << '\n';
    return 0;
}
