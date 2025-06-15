#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll x;
ll len[51], patty[51];

int n;

ll Eat(int l)
{
	if(l==0) return x >= 1 ? 1:0;
	// 번만 먹어야 하는 경우
    if(x==1) return 0;
	// 먹는 위치가 패티까지일 경우
    else if(len[l-1]+2== x) return patty[l-1] + 1;
	// 먹는 위치가 아래 빵까지일 경우
	else if(len[l-1] + 2 > x) 
	{
		x--;
		return Eat(l-1);
	}
	// 먹는 위치가 위쪽 빵까지일 때
	else
	{
		x -= len[l-1]+2;
		return Eat(l-1) + patty[l-1] + 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;
	
	len[0] = patty[0] = 1;
	for(int i=1; i<=n; i++)
	{
		len[i] = len[i-1] * 2 + 3;
		patty[i] = patty[i-1] * 2 + 1;
	}
	
	
	cout << Eat(n);
	
	return 0;
}
