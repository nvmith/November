#include <bits/stdc++.h>

using namespace std;

tuple<int,int,int> edges[1000005];
vector<int> p(100005, -1);

int n,m;
int maxWeight = 0;

int find(int x)
{
    if(p[x]<0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v, int cost)
{
    u = find(u); v = find(v);
    
    if(u==v) return false;
    if(p[u]==p[v]) p[u]--;
    if(p[u]<p[v]) p[v] = u;
    else p[u] = v;
    
    maxWeight = max(maxWeight, cost);
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<m;i++)
    {
        int cost, vertex1, vertex2;
        cin >> vertex1 >> vertex2 >> cost;
        edges[i] = {cost, vertex1, vertex2};
    }
    
    sort(edges, edges + m);
    
    int cnt = 0;
    int sum = 0;
    
    for(int i=0;i<m;i++)
    {
        int cost, vertex1, vertex2;
        tie(cost, vertex1, vertex2) = edges[i];
        
        if(!is_diff_group(vertex1, vertex2, cost)) continue;
        
        sum += cost;
        cnt++;
        
        if(cnt == n-1) break;
    }
    
    cout << sum-maxWeight;
}
