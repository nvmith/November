#include <bits/stdc++.h>
using namespace std;

int a[100002];
int ra[100002];
int n,h;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> h;
	
	for(int i=0; i<n; i++)
	{
		if(i%2 == 0) cin >> a[i/2];
		else cin >> ra[i/2];
	}
	
	sort(a, a + n/2);
	sort(ra, ra + n/2);
	
	int cnt = 0x7ffffff, area = 0;
	for(int i=1; i<=h; i++)
	{
		int temp = 0;

		temp = n/2 - (lower_bound(a, a+n/2, i) - a);
		temp += n/2 - (lower_bound(ra, ra+n/2, h-i+1)- ra);

		if(temp < cnt)
		{
			cnt = temp;
			area = 1;
		}
		else if(temp == cnt) area++;
	}
	
	cout << cnt << ' ' << area;
	
	return 0;
}
