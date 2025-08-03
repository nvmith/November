#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> um;

bool isParents(string a, string b) 
{
    while(um.count(b))
    {
        b = um[b];
        if (b == a) return true;
    }
    return false;
}

int main() 
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int n;
    cin >> n;
    
    string child, parent;
    
    for(int i=0; i<n-1; i++) 
    {
        cin >> child >> parent;
        um[child] = parent;
    }

    cin >> child >> parent;

    cout << (isParents(child, parent) || isParents(parent, child));
}
