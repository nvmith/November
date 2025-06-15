#include <bits/stdc++.h>

using namespace std;

int arr[130][130];
int cnt[2];
int n;

void divide(int left,int right, int bottom, int top)
{
	int mid, midH;
	bool is = true;
	if (left < right)
	{
	    for(int i=left;i<right;i++)
	    {
            for(int j=bottom;j<top;j++)
            {
                if(arr[i][j]!=arr[left][bottom]) 
                {
                    is = false;
                    break;
                }
            }
	    }
	    
	    if(is) cnt[arr[left][bottom]]++;
	    else
	    {
    		mid = (left + right) / 2;
    		midH = (bottom + top) / 2;
    		divide(left, mid, bottom, midH);
    		divide(mid, right, bottom, midH);
    		divide(left, mid, midH, top);
    		divide(mid, right, midH, top);
	    }
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
            
    divide(0, n, 0, n);
            
    cout << cnt[0] << '\n' << cnt[1];
}
