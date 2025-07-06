#include <bits/stdc++.h>

using namespace std;

int n;

vector<string> result;

void func(int next, string st, int cur, int last)
{
    if (next > n)
    {
        if (cur == 0)
            result.push_back(st);
        return;
    }
    
    // 덧셈
    func(next + 1, st + "+" + to_string(next), cur + next, next);
    
    // 뺄셈
    func(next + 1, st + "-" + to_string(next), cur - next, -next);

    // 공백
    int space = last >= 0 ? last * 10 + next : last * 10 - next;
    func(next + 1, st + " " + to_string(next), cur - last + space, space);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    
    cin >> t;
    
    while(t--)
    {
        cin >> n;
        
        result.clear();
        
        func(2, "1", 1, 1);
        
        sort(result.begin(), result.end());
        
        for(int i=0;i<result.size();i++)
            cout << result[i] << '\n';
        
        cout << '\n';
    }
}
