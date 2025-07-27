#include <bits/stdc++.h>
using namespace std;

int s[202][202];
int n,m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			int num;
			cin >> num;
			s[i][j] = num + s[i][j-1] + s[i-1][j] - s[i-1][j-1];
		}
	}
	
	int result = -0x7fffffff;
	
	for(int x=1; x<=n; x++)
	{
		for(int y=1; y<=m; y++)
		{
			for(int i=x; i<=n; i++)
			{
				for(int j=y; j<=m; j++)
				{
					result = max(result, s[i][j]-s[i][j-y]-s[i-x][j]+s[i-x][j-y]);
				}
			}
		}
	}
	
	cout << result;
	
	return 0;
}
