#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int arr[12];
bool check[12];
int n, k;
int cnt = 0;

void combine(int num)
{
	if(cnt == k)
	{
		v.push_back(num);
		return;
	}

	for(int i=0; i<n; i++)
	{
		if(check[i]) continue;
		check[i] = 1;
		cnt++;
		
		if(arr[i] >= 10) num *= 100;
		else num *= 10;
		
		combine(num + arr[i]);
		
		if(arr[i] >= 10) num /= 100;
		else num /= 10;
		
		check[i] = 0;
		cnt--;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> arr[i];
		
	combine(0);

		
	sort(v.begin(), v.end());
	
	int result = 0;
	int temp = -1;
	
	for(auto vec : v)
	{
		if(temp == vec) continue;
		temp = vec;
		result++;
	}

	cout << result << '\n';
	
	return 0;
}
