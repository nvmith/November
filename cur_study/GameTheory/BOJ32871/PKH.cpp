#include <iostream>
using namespace std;

#define ll long long

ll t;
ll n,m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		
		if(n == 1 || m == 1 || (n != m) && (n+m)%2 == 1) cout << "YES\n";
		else cout << "NO\n";
	}
	
	
	return 0;
}
