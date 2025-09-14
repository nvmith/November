#include <bits/stdc++.h>

using namespace std;

int sumDigits(string s) 
{
    int sum = 0;
    for (char c : s) if (isdigit(c)) sum += c - '0';
    return sum;
}

bool cmp(const string &a, const string &b)
{
	if (a.size() != b.size())
		return a.size() < b.size();
	else
	{
		int sumA = sumDigits(a);
		int sumB = sumDigits(b);
		
		if(sumA != sumB)
			return sumA < sumB;
		else
			return  a < b;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> st;
	st.resize(n);

	for(int i=0; i<n; i++)
		cin >> st[i];
	
	sort(st.begin(), st.end(), cmp);
	
	for(int i=0; i<n; i++)
	    cout << st[i] << '\n';
}
