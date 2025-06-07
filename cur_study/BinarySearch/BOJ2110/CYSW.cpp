#include <bits/stdc++.h>
using namespace std;

int houses[200002];

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,c,result=0;
	
	cin >> n >> c;
	
	for(int i=0;i<n;i++)
	    cin >> houses[i];
	
	sort(houses, houses+n);
	
	int start = 1;
	int end = houses[n-1];
	
	while(start<=end)
	{
	    int cnt = 1;
        int mid = (start + end) / 2;
        int cur = houses[0];
        for (int i = 1; i < n; i++)
        {
            if (houses[i] - cur >= mid)
            {
                cnt++;
                cur = houses[i];
            }
        }
	    
	    if(cnt >= c)
	    {
	        result = mid;
	        start = mid+1;
	    }
	    else end = mid-1;
	}
	
	cout << result;
	
	return 0;
}
