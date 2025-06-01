#include <bits/stdc++.h>
using namespace std;

int a[10002];
int n,m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
		
	cin >> m;
	
	sort(a, a+n);
	
	int st = 0, en = a[n-1];
	int mid = 0, result=0;
	
	while(st <= en)
	{
		mid = (st+en)/2;
		int sum = 0;
		for(int i=0; i<n; i++)
		{
			if(a[i] <= mid) sum += a[i];
			else sum += mid;
			
		}

		if(m > sum) {
			st = mid+1;
			result = mid;
		}
		else if(m < sum) en = mid-1;
		else
		{
			result = mid;
			break;
		}
	}
	
	cout << result;
	
	return 0;
}
