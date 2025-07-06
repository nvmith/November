#include <bits/stdc++.h>
using namespace std;

char A[1026][1026];
int t;

int GetSum(int sx, int sy, int size) {
   int sum = 0;
   for (int i = sx; i < sx + size; i++)
      for (int j = sy; j < sy + size; j++)
         sum += A[i][j];
   return sum;
}

int Cookie(int sx, int sy, int size) {
   if (size == 1) return A[sx][sy];

   int half = size / 2;
   int totalSum = GetSum(sx, sy, size);
   int eaten = totalSum % 4;

   int sum = 0;
   for (int i = 0; i < 4; i++) {
      if (i == eaten) continue;
      int nx = sx + (i / 2) * half; // 사분면 공식
      int ny = sy + (i % 2) * half;
      sum += Cookie(nx, ny, half);
   }
   return sum;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> t;
   while (t--) {
      int n;
      cin >> n;

      for (int i = 0; i < n; i++){
         string s;
         cin >> s;
         for(int j=0; j<n; j++)
            A[i][j] = s[j] - '0';
      }
      cout << Cookie(0, 0, n) << '\n';
   }
}
