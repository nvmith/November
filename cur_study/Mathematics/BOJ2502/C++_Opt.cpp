#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int d, k;
    cin >> d >> k;

    int fib[31];
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= d; i++) 
        fib[i] = fib[i-1] + fib[i-2];

    int coeA = fib[d-2];
    int coeB = fib[d-1];

    for (int a = 1; a <= k / coeA; a++) {
        int tmp = k - coeA * a;
        if (tmp % coeB == 0) {
            int b = tmp / coeB;
            if (b > 0) {
                cout << a << '\n' << b;
                return 0;
            }
        }
    }
}
