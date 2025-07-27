#include <bits/stdc++.h>
using namespace std;

int n, k;
int d[100002];
int s[100002];
int result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for(int i=0; i<n;i++)
		cin >> d[i];
	
	s[0] = d[0];

	for(int i=1; i<n; i++)
		s[i] = s[i-1] + d[i];
	
	result = s[k-1];
	
	for(int i=0; i<n-k; i++)
		result = max(result, s[i+k]-s[i]);

	cout << result;
	
	return 0;
}
