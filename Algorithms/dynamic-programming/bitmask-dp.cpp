#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*

CPH: [Bitmask DP] Optimal selection
We are given the prices of k products over n days, and we want to buy each product exactly once. However,
we are allowed to buy at most one product in a day. What is the minimum total
price? For example, consider the following scenario ( k = 3 and n = 8):

k n
3 8
 
days:      0 1 2 3 4 5 6 7  
product 0: 6 9 5 2 8 9 1 6
product 1: 8 2 6 2 7 5 7 2
product 2: 5 3 9 7 3 5 1 4
 
 */
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int k, n;
   cin >> k >> n;
   vector price(k, vector(n, 0));
   for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++) {
         cin >> price[i][j];
      }
   }

   vector dp(1 << k, vector(n, int(1e9)));
   for (int i = 0; i < n; i++) dp[0][i] = 0;
   for (int i = 0; i < k; i++) dp[1 << i][0] = price[i][0];

   for (int j = 1; j < n; j++) {
      for (int mask = 0; mask < (1 << k); mask++) {
         dp[mask][j] = dp[mask][j - 1];
         for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
               dp[mask][j] = min(dp[mask][j], dp[mask ^ (1 << i)][j - 1] + price[i][j]);
            }
         }
      }
   }
   cout << dp[(1 << k) - 1][n - 1];
   return 0;
}

