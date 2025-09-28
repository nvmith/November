#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n;

    vector<int> a(n);
    
    for(int i=0; i<n; i++) 
        cin >> a[i];
        
    cin >> s;

    for(int i=0; i<n && s>0; i++)
    {
        int limit = min(n-1, i+s);
        auto it = max_element(a.begin()+i, a.begin()+limit+1);
        int pos = int(it-a.begin());
        
        if(pos==i) continue;

        rotate(a.begin()+i, a.begin()+pos, a.begin()+pos+1);
        s -= (pos-i);
    }

    for(int i=0; i<n; i++)
        cout << a[i] << ' ';
}
