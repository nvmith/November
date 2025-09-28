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
        int pos = i;
    
        for (int j=i+1; j<=limit; j++) 
        {
            if (a[j] > a[pos])
                pos = j;
        }
        
        int val = a[pos];
        
        for (int j=pos; j>i; j--) 
            a[j] = a[j-1];
            
        a[i] = val;
        s -= (pos-i);
    }

    for(int i=0; i<n; i++) 
        cout << a[i] << ' ';
}
