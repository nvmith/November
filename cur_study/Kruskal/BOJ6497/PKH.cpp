#include <bits/stdc++.h>
using namespace std;

tuple<int,int,int> g[200002];
int m,n;
int p[200002];

int find(int x)
{
	if(p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
	u = find(u), v = find(v);
	if(u == v) return 0;
	
	if(p[u]==p[v]) p[u]--;
	if(p[u] < p[v]) p[v]= u;
	else p[u]=v;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(1)
	{
		cin >> m >> n;
		if(m == 0 && n == 0) break;
		
		fill(p,p+n,-1);
		
		int sum = 0;
		for(int i=0; i<n; i++)
		{
			int cost, x, y;
			cin >> x >> y >> cost;
			g[i] = {cost,x+1,y+1};
			sum += cost;
		}
		
		sort(g, g+n);
		int cnt = 0, ev = 0;
		for(int i=0; i<n; i++)
		{
			int cost, x, y;
			tie(cost,x,y) = g[i];
			if(!uni(x,y)) continue;
			ev += cost; 
			cnt++;
			if(cnt == m-1) break;
		}

		cout << sum - ev << '\n';
	}
	
	return 0;
}
