#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> dist[10002];

vector<int> p(1002, -1);
char s[1002];

int find(int x)
{
	if(p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool is_different_group(int u, int v)
{
	u = find(u); v = find(v);
	if(u == v) return 0;
	if(p[u] == p[v]) p[u]--;
	if(p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    
    cin >> n >> m;
    
    for(int i=1;i<n+1;i++)
        cin >> s[i];
        
    for(int i=0;i<m;i++)
    {
        int a,b,cost;
        cin >> a >> b >> cost;
        dist[i] = {cost,a,b};
    }
    
    sort(dist, dist+m);
    
    int cnt=0;
    int sum = 0;
    
    for(int i=0;i<m;i++)
    {
        int a,b,cost;
        tie(cost,a,b) = dist[i];
        if(s[a] == s[b]) continue;
        if(!is_different_group(a,b)) continue;
        cnt++;
        sum += cost;
        if(cnt == n-1) break;
    }
    
    if(cnt == n-1) cout << sum;
    else cout << -1;
}
