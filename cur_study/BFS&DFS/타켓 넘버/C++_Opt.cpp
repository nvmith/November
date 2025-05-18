// DFS 최적화
#include <bits/stdc++.h>

using namespace std;

int cnt;

void DFS(const vector<int> &v, int &result, int idx, int sum)
{
    if(idx == v.size()-1)
    {
        if(sum == result) cnt++;
        return;
    }
    DFS(v, result, idx+1, sum + v[idx+1]);
    DFS(v, result, idx+1, sum - v[idx+1]);
}

int solution(vector<int> v, int target) {
    
    DFS(v,target, 0, -v[0]);
    DFS(v,target, 0, v[0]);
    
    return cnt;
}

// BFS 최적화
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> v, int target) {
    int cnt = 0;
    int n = v.size();
    queue<pair<int,int>> q; // {idx, sum}
    q.push({0,v[0]});
    q.push({0,-v[0]});
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        int idx = cur.first;
        int sum = cur.second;
        
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
