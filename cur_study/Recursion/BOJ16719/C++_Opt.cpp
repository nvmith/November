#include <bits/stdc++.h>
using namespace std;

string s;
bool used[101];

void solve(int l, int r) 
{
    if (l > r) return;
    
    int idx = -1;
    char mn = 'Z' + 1;
    
    for (int i=l; i<=r; i++)
        if (!used[i] && s[i] < mn)
            mn = s[i], idx = i;

    if (idx==-1) return;

    used[idx] = true;

    for (int i=0; i<s.size(); i++)
        if (used[i]) cout << s[i];
    cout << '\n';

    solve(idx+1, r);
    solve(l, idx-1);
}

int main() 
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin >> s;
    solve(0, s.size()-1);
}
