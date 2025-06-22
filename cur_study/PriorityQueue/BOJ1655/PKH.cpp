#include <bits/stdc++.h>
using namespace std;

#define pa pair<int,int>

priority_queue<int> mx;
priority_queue<int,vector<int>, greater<int>> mn;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		int a;
		cin >> a;
		
		if(mx.empty() || mx.top() >= a) mx.push(a);
		else mn.push(a);
		if(mx.size() > mn.size() + 1)
		{
			mn.push(mx.top());
			mx.pop();
		}
		else if(mn.size() > mx.size())
		{
			mx.push(mn.top());
			mn.pop();
		}
		
		cout << mx.top() << '\n';
	}
	
	return 0;
}
