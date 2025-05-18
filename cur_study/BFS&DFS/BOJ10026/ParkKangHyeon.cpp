#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string area[102];
int arr1[102][102];
int arr2[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, cnt1, cnt2, color;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		string s;
		cin >> area[i];
		for(int j=0; j<n; j++)
		{
			if(area[i][j] == 'R') 
			{
				arr1[i][j] = 1;
				arr2[i][j] = 1;
			}
			else if(area[i][j] == 'G') 
			{
				arr1[i][j] = 2;
				arr2[i][j] = 1;
			}
			else 
			{
				arr1[i][j] = 3;
				arr2[i][j] = 2;
			}
		}
	}

	queue<pair<int,int>> q1;
	queue<pair<int,int>> q2;
	
	for(int x=0; x<n; x++)
	{
		for(int y=0; y<n; y++)
		{
			if(arr1[x][y]==0) continue;
			q1.push({x,y});
			color = arr1[x][y];
			arr1[x][y] = 0;

			while(!q1.empty())
			{
				auto cur = q1.front(); q1.pop();
				for(int i=0; i<4; i++)
				{
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if(nx < 0 || ny <0 || nx >= n || ny >= n) continue;
					if(arr1[nx][ny]==0 || color != arr1[nx][ny]) continue;
					arr1[nx][ny] = 0;
					q1.push({nx,ny});
				}
			}
			cnt1++;
		}
	}
	
	for(int x=0; x<n; x++)
	{
		for(int y=0; y<n; y++)
		{
			if(arr2[x][y]==0) continue;
			q2.push({x,y});
			color = arr2[x][y];
			arr2[x][y] = 0;

			while(!q2.empty())
			{
				auto cur = q2.front(); q2.pop();
				for(int i=0; i<4; i++)
				{
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if(nx < 0 || ny <0 || nx >= n || ny >= n) continue;
					if(arr2[nx][ny]==0 || color != arr2[nx][ny]) continue;
					arr2[nx][ny] = 0;
					q2.push({nx,ny});
				}
			}
			
			cnt2++;
		}
	}
	
	cout << cnt1 << ' ' << cnt2;
	
	return 0;
}
