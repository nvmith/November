#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> graph[1000002];
int n, m, cnt, w;

vector<int> p(1000002, -1);

int find(int x)
{
	if(p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
	u = find(u); v = find(v);
	if(u == v) return 0;
	if(p[u] == p[v]) p[u]--;
	if(p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	if(n==2)
	{
		cout << 0;
		return 0;
	}
	
	for(int i=0; i<m; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		graph[i] = {cost, a, b};
	}
	
	sort(graph, graph+m);
	
	for(int i=0; i<m; i++)
	{
		int cost, a, b;
		tie(cost,a,b) = graph[i];
		if(!uni(a,b)) continue;
		w += cost;
		cnt++;
		if(cnt >= n-2) break;
	}

	cout << w;
	
	return 0;
}
