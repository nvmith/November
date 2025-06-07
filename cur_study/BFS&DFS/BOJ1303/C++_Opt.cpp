#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char arr[102][102];
bool vis[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m,w,b;

void BFS(int x, int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	vis[x][y] = 1;
	int cnt = 0;
	
	while(!q.empty())
	{
		auto cur = q.front(); q.pop();
		cnt++;
		for(int i=0; i<4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if(nx <0 || ny <0 || nx>=m || ny>=n) continue;
			if(vis[nx][ny] || arr[x][y] != arr[nx][ny]) continue;
			q.push({nx,ny});
			vis[nx][ny] = 1;
		}
	}
	
	if(arr[x][y] == 'B') b += cnt * cnt;
	else w += cnt * cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin >> arr[i][j];
	
	for(int i=0; i<m; i++)
	{
		for(int j=0;j<n;j++)
		{
			if(vis[i][j]) continue;
			 BFS(i,j);
		}
	}
	
	cout << w << ' ' << b;
	
	return 0;
}
