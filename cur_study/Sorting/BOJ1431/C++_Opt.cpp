#include <bits/stdc++.h>

using namespace std;

struct Item {
    string s;
    int len;
    int sum;
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Item> v(n);

    for(int i = 0; i < n; i++) 
    {
        cin >> v[i].s;
        v[i].len = (int)v[i].s.size();
        int sum = 0;
        for (char c : v[i].s) if ('1' <= c && c <= '9') sum += c - '0';
        v[i].sum = sum;
    }

    sort(v.begin(), v.end(), [](const Item& a, const Item& b) {
        if (a.len != b.len) return a.len < b.len;
        if (a.sum != b.sum) return a.sum < b.sum;
        return a.s < b.s;
    });

    for(int i = 0; i < n; i++)
        cout << v[i].s << '\n';
}
