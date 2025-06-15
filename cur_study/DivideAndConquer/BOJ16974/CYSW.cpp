#include <bits/stdc++.h>

using namespace std;

vector<long long> len; //인덱스당 전체 크기
vector<long long> patty; //인덱스당 패티 개수

long long pattyCnt(int level, long long x) //x는 레이어의 수
{
    if (level == 0) return (x >= 1 ? 1 : 0);
    if (x == 1) return 0; //먹을 레이어가 1보다 작으면 패티수는 없어
    else if (x <= 1 + len[level - 1]) return pattyCnt(level - 1, x - 1); //먹을 레이어가 만약에 중앙보다 적다면 다시 왼쪽 재귀
    else if (x == len[level - 1] + 2) return patty[level - 1] + 1; //먹을 레이어가 딱 중앙 패티까지라면 그전까지의 패티 수 + 중앙 패티
    else if (x <= len[level]) return patty[level - 1] + 1 + pattyCnt(level - 1, x - 2 - len[level - 1]); //먹을 레이어가 중앙보다 많다면 패티 수 + 중앙 패티 + 오른쪽 재귀(x-2는 첫 번과 중앙패티 뺀것, len[level-1]은 상대 위치)
    else return patty[level]; //먹을 레이어가 전부라면 그냥 리턴
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, x;
    
    cin >> n >> x;
    
    len.push_back(1);
    patty.push_back(1);

    for (int i = 1; i <= n; i++) 
    {
        patty.push_back((1LL << (i + 1)) - 1);
        len.push_back((1LL << (i + 2)) - 3);
    }
    
    cout << pattyCnt(n,x);
}
