#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int t, n;

void zero(int num, string s, int sum, int last)
{
	if(num > n)
	{
		if(sum==0)
			v.push_back(s);
		return;
	}
	
	zero(num+1, s+"+" + to_string(num), sum+num,num);
	zero(num+1, s+"-" + to_string(num), sum-num,-num);
	int space = last >= 0 ? last*10 + num : last*10 - num;
	zero(num+1, s+" "+to_string(num), sum - last + space, space);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		zero(2,"1",1,1);
		
		sort(v.begin(), v.end());
		
		for(auto vec : v)
			cout << vec << '\n';
		v.clear();
		cout << '\n';
	}
	
	return 0;
}
