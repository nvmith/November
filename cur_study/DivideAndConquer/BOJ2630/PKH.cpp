#include <bits/stdc++.h>
using namespace std;

int arr[129][129];
int n, w, b; // white, blue cnt

void divide(int sx, int ex, int sy, int ey)
{
	if(sx+1 == ex || sy+1 == ey)
	{
		if(arr[sx][sy]) b++;
		else w++;
		return;
	}
	
	for(int i=sx; i<ex; i++)
	{
		for(int j=sy; j<ey; j++)
		{
			if(arr[sx][sy] != arr[i][j])
			{
				int mx = (sx+ex)/2;
				int my = (sy+ey)/2;
				divide(sx, mx, sy, my);
				divide(sx, mx, my, ey);
				divide(mx, ex, sy, my);
				divide(mx, ex, my, ey);
				return;
			}
		}
	}
	if(arr[sx][sy]) b++;
	else w++;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> arr[i][j];
	
	divide(0,n,0,n);
	
	cout << w << '\n' << b;
	
	return 0;
}
