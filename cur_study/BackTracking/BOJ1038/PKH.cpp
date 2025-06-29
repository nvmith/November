#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> v;
int n;

void up(ll num, int i)
{
	v.push_back(num);
	for(int x=0; x<i; x++) up(num*10+x,x);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	v.push_back(0);
	
	for(int i=9; i>0; i--) up(i,i);
		
	sort(v.begin(), v.end());
	
	if(v.size() <= n) cout << -1;
	else cout << v[n];
	
	return 0;
}
