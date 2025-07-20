#include <bits/stdc++.h>
using namespace std;

string city[200002];
string code[200002];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	unordered_map<string, int> r; // relation
	
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		cin >> city[i] >> code[i];
		if(city[i].substr(0,2) != code[i])
		{
			string s = city[i].substr(0,2) + code[i];
			r[s]++;
		}
	}
	
	int cnt =0;
	
	for(int i=0; i<n; i++)
	{
		if(city[i].substr(0,2) != code[i])
		{
			string s = code[i] + city[i].substr(0,2);
			cnt += r[s];
		}
	}
	
	cout << cnt/2;
	
	return 0;
}
