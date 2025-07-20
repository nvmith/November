#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<string, unordered_map<string, int>> um;

    for (int i = 0; i < n; i++) 
    {
        string city, state;
        cin >> city >> state;
        city = city.substr(0, 2);
        if (city != state)
            um[state][city]++;
    }

    int result = 0;

    for (auto [s, m] : um)
        for (auto [key, cnt] : m)
            if (um.count(key) && um[key].count(s)) 
                result += cnt * um[key][s];

    cout << result / 2;
}
