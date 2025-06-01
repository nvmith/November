#include <bits/stdc++.h>
using namespace std;

int arr[10002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m, mx = 0;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
		
	cin >> m;
	
	int st = 0, en = mx;
	int mid = 0, result=0;
	
	while(st <= en)
	{
		mid = (st+en)/2;
		int sum = 0;
		for(int i=0; i<n; i++)
			sum += min(arr[i], mid);

		if(m > sum) 
        {
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
