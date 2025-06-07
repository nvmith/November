#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> c;
	for(int i=0; i<n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());
	
	int st = 1, en = v.back()-v.front();
	int result = 0x7fffffff;

	while(st <= en)
	{
		int mid = (st+en)/2;
		int cnt = 1, cur = v[0];
		for(int i=1; i<v.size(); i++)
			if(v[i] - cur >= mid) {
				cur = v[i];
				cnt++;
			}

		if(cnt >= c) 
		{
			result = mid;
			st = mid + 1;
		}
		else en = mid -1;
	}
	
	cout << result << '\n';
	
	return 0;
}
