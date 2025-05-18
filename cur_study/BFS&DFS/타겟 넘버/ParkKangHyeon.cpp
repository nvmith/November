// DFS (재귀)
#include <bits/stdc++.h>

using namespace std;

vector<int> vec;
int n, result, cnt;

void DFS(int idx, int sum)
{
    if(idx == n-1)
    {
        if(result == sum) cnt++;
        return;
    }
    
    DFS(idx+1, sum + vec[idx+1]);
    DFS(idx+1, sum - vec[idx+1]);
}

int solution(vector<int> v, int target) {
    n = v.size();
    result = target;
    vec = v;
    DFS(0, vec[0]);
    DFS(0, -vec[0]);
    
    return cnt;
}

// BFS(Queue)
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int solution(vector<int> v, int target) {
    int cnt = 0;
    int n = v.size();
    queue<pair<int,int>> q; // {idx, sum}
    q.push({0,v[0]});
    q.push({0,-v[0]});
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        int idx = cur.X;
        int sum = cur.Y;
        
        if(idx == n-1)
        {
            if(sum == target) cnt++;
            continue;
        }
        q.push({idx+1, sum + v[idx+1]});
        q.push({idx+1, sum - v[idx+1]});
    }
    
    return cnt;
}

