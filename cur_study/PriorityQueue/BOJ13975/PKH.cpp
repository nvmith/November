#include <bits/stdc++.h>
using namespace std;

#define ll long long

int t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	
	while(t--)
	{
		priority_queue<ll,vector<ll>, greater<ll>> pq;
		ll k, sum =0;
		cin >> k;
		
		for(int i=0; i<k; i++)
		{
			int a;
			cin >> a;
			pq.push(a);
		}
		
		
		while(pq.size() > 1)
		{
			ll a = pq.top(); pq.pop();
			a += pq.top(); pq.pop();
			sum += a;
			pq.push(a);
		}
		
		cout << sum << '\n';
	}

	return 0;
}
