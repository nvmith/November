#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> city[200002];
vector<int> p(200002, -1);

int find(int x)
{
	if(p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool isUnion(int u, int v)
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
	
	while(true)
	{
	    int allCost = 0;
	    fill(p.begin(), p.end(), -1);
	    int n, m, cnt=0, w=0;
	    
	    cin >> m >> n;
    	if(!m && !n) break;
	    
	    for(int i=0; i<n;i++)
	    {
	        int a, b, cost;
    	    cin >> a >> b >> cost;
    	    city[i] = {cost, a, b};
    	    allCost += cost;
	    }
    	
    	sort(city, city+n);
    	
    	for(int i=0; i<n; i++)
    	{
    		int cost, a, b;
    		tie(cost,a,b) = city[i];
    		if(!isUnion(a,b)) continue;
    		w += cost;
    		cnt++;
    		if(cnt == m-1) break;
    	}
    	cout << allCost - w << '\n';
	}
	
	return 0;
}
