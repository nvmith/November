#include <bits/stdc++.h>

using namespace std;

int n,k,card[10];
string cur;
bool isUsed[10];
unordered_set<int> s;

void func(int d)
{
    if(d==k)
    {
        s.insert(stoi(cur));
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if(!isUsed[i])
        {
            string tmp = cur;
            isUsed[i] = 1;
            cur += to_string(card[i]);
            func(d+1);
            cur = tmp;
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
