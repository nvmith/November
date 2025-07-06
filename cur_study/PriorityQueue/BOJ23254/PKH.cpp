#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int a[200002], b[200002];
int n, m;

priority_queue<pair<int,int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	int sum = 0;
	
	for(int i=0; i<m; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	for(int i=0; i<m; i++)
	{
		cin >> b[i];
		pq.push({b[i],a[i]});
	}
	
	n*=24;
	
	while(n>0)
	{
		if(pq.empty()) break;
		auto cur = pq.top(); pq.pop();
		
		if(cur.Y + cur.X == 100)
		{
			sum += cur.X;
			n--;
		}
		else if(cur.Y + cur.X < 100)
		{
			sum += cur.X;
			pq.push({cur.X , cur.X+cur.Y});
			n--;
		}
		else
		{
			if(cur.Y != 100) pq.push({cur.X-(cur.X+cur.Y-100), cur.Y});
		}
	}
	
	cout << sum;
	
	return 0;
}
