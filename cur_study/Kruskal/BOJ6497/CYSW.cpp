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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    vector<int> result;
	
	while(true)
	{
	    int allCost = 0;
	    
	    fill(p.begin(), p.end(), -1);
	    for (int i = 0; i < 200002; ++i) 
            city[i] = make_tuple(0, 0, 0);
	    
	    int n, m, cnt=0, w=0;
	    
	    cin >> m >> n;
	    
    	if(!m && !n) break;
	    
	    for(int i=0; i<n;i++)
	    {
	        int a, b, cost = 0;
    	    cin >> a >> b >> cost;
    	    city[i] = {cost, a, b};
    	    allCost += cost;
	    }
	    
	    if(m-n == 1) 
	    {
	        result.push_back(0);
	        continue;
	    }
    	
    	sort(city, city+n);
    	
    	for(int i=0; i<n; i++)
    	{
    		int cost, a, b;
    		tie(cost,a,b) = city[i];
    		if(!isUnion(a,b)) continue;
    		cnt++;
    		if(cnt == n) break;
    		w += cost;
    	}
    	result.push_back(allCost - w);
	}
	
	for(int i=0;i<result.size();i++)
	    cout << result[i] << '\n';
	
	return 0;
}
