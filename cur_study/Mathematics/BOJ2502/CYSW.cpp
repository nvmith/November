#include <bits/stdc++.h>

using namespace std;

int fib(int n)
{
    if(n <= 2) return 1;
    int a = 1, b = 1;
    for(int i=3; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int d, k;
    cin >> d >> k;

    int coeA = fib(d - 2);
    int coeB = fib(d - 1);

    for(int a=1; a <= k; a++)
    {
        int tmp = k - coeA * a;
        if(tmp % coeB == 0)
        {
            int b = tmp / coeB;
            if (b > 0)
            {
                cout << a << '\n' << b;
                return 0;
            }
        }
    }
}
