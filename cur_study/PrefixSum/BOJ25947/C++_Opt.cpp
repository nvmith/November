#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int costs[100002];
ll psum[100002];

int main() 
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int n,b,a;
    
    cin >> n >> b >> a;
    
    for(int i=0; i<n; i++)
        cin >> costs[i];

    sort(costs, costs+n);
    
    for(int i=0; i<n; i++)
        psum[i+1] = psum[i]+costs[i];

    int low = 0, high = n, result = 0;

    while(low<=high)
    {
        int mid = (low+high)/2;
        ll discountSum = psum[mid] - psum[mid-min(mid, a)];
        ll cost = psum[mid] - discountSum / 2;

        if(cost<=b)
        {
            result = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }

    cout << result;
}
