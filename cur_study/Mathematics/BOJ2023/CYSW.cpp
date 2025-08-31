#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) 
{
    if(x < 2) return 0;
    for(int i = 2; i * i <= x; i++) 
        if(x % i == 0) return 0;
    return 1;
}


void makeNum(int num, int len, int n) 
{
    if(len == n) 
    {
        cout << num << "\n";
        return;
    }
    for(int d : {1, 3, 7, 9}) 
    {
        int next = num * 10 + d;
        if (isPrime(next)) makeNum(next, len + 1, n);
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int p : {2, 3, 5, 7}) 
        makeNum(p, 1, n);
}
