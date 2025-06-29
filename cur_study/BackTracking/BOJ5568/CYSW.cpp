#include <bits/stdc++.h>

using namespace std;

int n,k, cnt;
int card[10];
int now[10];
bool isUsed[100];
set<int> s;

void func(int d)
{
    if(d==k && !s.count(d))
    {
        string st;
        for(int i=0;i<k;i++)
            st += to_string(now[i]);
        
        if(!s.count(stoi(st)))
            s.insert(stoi(st));
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if(!isUsed[i])
        {
            now[d] = card[i];
            isUsed[i] = 1;
            func(d+1);
            isUsed[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    for(int i=0;i<n;i++)
        cin >> card[i]; 
        
    func(0);
    
    cout << s.size();
}
