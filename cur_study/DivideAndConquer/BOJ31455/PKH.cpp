#include <bits/stdc++.h>
using namespace std;

char A[1026][1026];
int t;

void Reset(int n)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			A[i][j] = -1;
}

void Cookie(int sx, int ex, int sy, int ey)
{
	int sum = 0;
	int mx = (sx+ex)/2;
	int my = (sy+ey)/2;
	
	if(ex == sx+1 || ey == sy+1) return;
	
	for(int i=sx; i<ex; i++)
		for(int j=sy; j<ey; j++)
			sum += A[i][j];
	
	sum%=4;
	
	if(sum == 0)
	{
		for(int i=sx; i<mx; i++)
			for(int j=sy; j<my; j++)
				A[i][j] = -1;
	}
	else Cookie(sx,mx,sy,my);
	
	if(sum == 1)
	{
		for(int i=sx; i<mx; i++)
			for(int j=my; j<ey; j++)
				A[i][j] = -1;
	}
	else Cookie(sx,mx,my, ey);
	
	
	if(sum == 2)
	{
		for(int i=mx; i<ex; i++)
			for(int j=sy; j<my; j++)
				A[i][j] = -1;
	}
	else Cookie(mx, ex, sy, my);
	
	if(sum == 3)
	{
		for(int i=mx; i<ex; i++)
			for(int j=my; j<ey; j++)
				A[i][j] = -1;
	}
	else Cookie(mx, ex, my, ey);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		
		Reset(n);
		
		int sum = 0;
		
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				cin >> A[i][j];
				A[i][j] -= '0';
			}
		
		Cookie(0,n,0,n);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(A[i][j] != -1)
					sum += A[i][j];
		
		cout << sum << '\n';
	}
	
	return 0;
}
