#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char arr[102][102];
bool vis[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, cnt, rgcnt;

int bfs()
{
	int result = 0;
	
	queue<pair<int,int>> q;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(vis[i][j]) continue;
			q.push({i,j});
			vis[i][j] = 1;
			bool check = false;
			while(!q.empty())
			{
				auto cur = q.front(); q.pop();
				for(int k=0;k<4; k++)
				{
					int nx = dx[k] + cur.X;
					int ny = dy[k] + cur.Y;
					
					if(nx <0 || ny <0 || nx >= n || ny >= n) continue;
					if(vis[nx][ny] || arr[nx][ny] != arr[cur.X][cur.Y]) continue;
					q.push({nx,ny});
					vis[nx][ny] = 1;
				}
			}
			result++;
		}
	}
	
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) 
			cin >> arr[i][j];
	
	cnt = bfs();
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) vis[i][j] = 0;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(arr[i][j] == 'R') arr[i][j] = 'G';
	
	rgcnt = bfs();
	
	cout << cnt << ' ' << rgcnt;
	
	return 0;
}
