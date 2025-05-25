#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> graph[1000002];

vector<int> p(100002, -1);

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
	
    int n=0, m=0, cnt=0, w=0;
    
	cin >> n >> m;
	
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
		cnt++;
		if(cnt == n-1) break;
		w += cost;
	}

	cout << w;
	
	return 0;
}
