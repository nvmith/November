#include <bits/stdc++.h>

using namespace std;

int n,m;

string board[102];
bool visited[102][102];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int,int>> b;
queue<pair<int,int>> w;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int powerB = 0;
    int powerW = 0;
    
    cin >> n >> m;
    
    for(int i=0;i<m;i++)
        cin >> board[i];
        
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int cnt = 1;
            if(visited[i][j]) continue;
            visited[i][j] = 1;
            if(board[i][j]=='B')
            {
                b.push({i,j});
                while(!b.empty())
                {
                    auto cur = b.front(); b.pop();
                    
                    for(int dir = 0; dir<4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(visited[nx][ny] || board[nx][ny] != 'B') continue;
                        visited[nx][ny] = 1;
                        b.push({nx,ny});
                        cnt++;
                    }
                }
                powerB += cnt * cnt;
            }
            else if(board[i][j]=='W')
            {
                w.push({i,j});
                while(!w.empty())
                {
                    auto cur = w.front(); w.pop();
                    
                    for(int dir = 0; dir<4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(visited[nx][ny] || board[nx][ny] != 'W') continue;
                        visited[nx][ny] = 1;
                        w.push({nx,ny});
                        cnt++;
                    }
                }
                powerW += cnt * cnt;
            }
        }
    }
    
    cout << powerW << ' ' << powerB;
}
