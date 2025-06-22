#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,m,result=0;
	
	cin >> n >> m;
	
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	
	for(int i=0;i<n;i++)
	{
	    int a;
	    cin >> a;
	    pq.push(a);
	}
    
    while (m--) 
    {
        auto curX = pq.top(); pq.pop();
        auto curY = pq.top(); pq.pop();
        
        pq.push(curX + curY);
        pq.push(curX + curY);
    }
    
    while(!pq.empty())
    {
        result += pq.top(); pq.pop();
    }
    
    cout << result;
    
    return 0;
}
