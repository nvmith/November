#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   int t;
   cin >> t;
   
   while(t--)
   {
       int k;
       ll cost = 0;
       cin >> k;
       priority_queue<ll, vector<ll>, greater<ll>> pq;
       
       for(int i=0; i<k; i++)
       {
          ll a;
          cin >> a;
          pq.push(a);
       }
       
       while(pq.size()!=1)
       {
          ll a = pq.top(); pq.pop();
          a += pq.top(); pq.pop();
          cost += a;
          pq.push(a);
       }
       
       cout << cost << '\n';
   }
   
   return 0;
}
