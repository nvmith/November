#include <bits/stdc++.h>

using namespace std;

vector<int> up;
vector<int> down;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,h;
    
    cin >> n >> h;
    
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if (i % 2 == 0) //아래에서 올라옴
            up.push_back(input);
        else //위에서 내려옴
            down.push_back(input);
    }
    
    sort(up.begin(), up.end());
    sort(down.begin(), down.end());
    
    int cnt = 0;
    int minObs = 500001;
    
    for(int i=1;i<=h;i++)
    {
        int u = up.end() - lower_bound(up.begin(), up.end(), i);
        int d = down.end() - lower_bound(down.begin(), down.end(), h - i + 1);
        int total = u + d;
        
        if (total < minObs)
        {
            minObs = total;
            cnt = 1;
        }
        else if (total == minObs)
            cnt++;
    }
    
    cout << minObs << ' ' << cnt;
}

//누적합 풀이 방식 (이진 탐색 아님)

//#include <bits/stdc++.h>

// using namespace std;

// int area[500000];

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
    
//     int n,h;
    
//     cin >> n >> h;
    
//     for (int i = 0; i < n; i++)
//     {
//         int input;
//         cin >> input;
//         if (i % 2 == 0) //아래에서 올라옴
//         {
//             area[0]++;
//             area[input]--;
//         }
//         else //위에서 내려옴
//         {
//             area[h - input]++;
//             area[h]--;
//         }
//     }
    
//     int minObs = 500001;

//     for (int i = 1; i < h; i++)
//     {
//         area[i] += area[i - 1];
//         minObs = min(minObs, area[i]);
//     }
    
//     int cnt = count(area, area + h, minObs);

//     cout << minObs << ' ' << cnt;
// }
