#include <bits/stdc++.h>

using namespace std;

bool used[102];
string s;

void zoac(string current) 
{
    if (current.size() == s.size()) return;

    string best = "Z";
    int bestIdx = -1;

    for (int i=0; i<s.size(); i++)
    {
        if (used[i]) continue;

        string tmp = current;

        for (int j=0; j<s.size(); j++)
        {
            if (used[j] || j==i)
                tmp += s[j];
        }

        if (tmp < best)
        {
            best = tmp;
            bestIdx = i;
        }
    }

    used[bestIdx] = true;

    string out = "";
    for (int i=0; i<s.size(); i++)
        if (used[i]) out += s[i];
    cout << out << '\n';

    zoac(out);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    zoac("");
}
