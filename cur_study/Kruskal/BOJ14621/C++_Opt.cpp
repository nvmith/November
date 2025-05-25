#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> g[10005];
char mw[1005];
int n, m, ans, cnt;

vector<int> p(1005,-1);

int find(int x)
{
	if(p[x] < 0) return x;
	else return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
	u = find(u); v = find(v);
	if(u==v) return 0;
	if(p[u] == p[v]) p[u]--;
	if(p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) cin >> mw[i];
	
	for(int i=0; i<m; i++)
	{
		int cost, a, b;
		cin >> a >> b >> cost;
		if(mw[a] == mw[b]) continue;
		g[cnt++] = {cost,a,b};
	}
	
	sort(g, g+cnt);
	int edgeCnt = 0;
	
	for(int i=0; i<cnt; i++)
	{
		int cost, a, b;
		tie(cost, a, b) = g[i];
		if(!uni(a,b)) continue;
		
		edgeCnt++;
		ans += cost;
		if(edgeCnt == n-1) break;
	}
	
	if(edgeCnt < n-1) cout << -1;
	else cout << ans;
	
	return 0;
}
