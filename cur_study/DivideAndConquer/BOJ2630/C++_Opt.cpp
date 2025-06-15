#include <bits/stdc++.h>
using namespace std;

int arr[129][129];
int cnt[2];

void divide(int startX, int endX, int startY, int endY)
{
    int color = arr[startX][startY];
    bool same = true;
    
    for(int i = startX; i < endX && same; i++)
        for(int j = startY; j < endY; j++)
            if(arr[i][j] != color) {
                same = false;
                break;
            }
    
    if(same) {
        cnt[color]++;
        return;
    }
    
    int midX = (startX + endX) / 2;
    int midY = (startY + endY) / 2;
    
    divide(startX, midX, startY, midY);
    divide(startX, midX, midY, endY);
    divide(midX, endX, startY, midY);
    divide(midX, endX, midY, endY);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    divide(0, n, 0, n);
    
    cout << cnt[0] << '\n' << cnt[1];
    return 0;
}
