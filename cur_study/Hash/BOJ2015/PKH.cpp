#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	unordered_map<ll, int> m;
	
	cin >> n >> k;
	
	m[0]=1;
	ll sum = 0, cnt =0, num =0;
	
	for(int i=1; i<=n; i++)
	{
		cin >> num;
		sum += num;
		
		cnt += m[sum-k];

		m[sum]++;
	}
	
	cout << cnt;
	
	return 0;
}
