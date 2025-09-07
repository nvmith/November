#include <bits/stdc++.h>

using namespace std;

vector<int> pay(100005, -1);
int coins[4] = {1,2,5,7};

int re(int n)
{
    if(n == 0) return 0;
    if(n < 0) return INT_MAX;
    if(pay[n] != -1) return pay[n];

    int best = INT_MAX;
    for(int c : coins)
    {
        if(n-c < 0) continue;
        
        int tmp = re(n-c);
        if(tmp+1 < best)
            best = tmp+1;
    }
    return pay[n] = best;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    
    cout << re(n);
}
