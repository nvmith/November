#include <bits/stdc++.h>
using namespace std;
#define ll long long

priority_queue<ll, vector<ll>, greater<ll>> pq;
int n, m;

int main() 
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   cin >> n >> m;
   for(int i=0; i<n; i++)
   {
      ll a;
      cin >> a;
      pq.push(a);
   }
   
   while(m--)
   {
      ll a = pq.top(); pq.pop();
      a += pq.top(); pq.pop();
      pq.push(a);
      pq.push(a);
   }
   
   ll sum = 0;
   while(!pq.empty())
   {
      sum += pq.top();
      pq.pop();
   }
   
   cout << sum;
   
   return 0;
}
