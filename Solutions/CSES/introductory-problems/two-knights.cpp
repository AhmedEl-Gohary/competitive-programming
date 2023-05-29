#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   ll x;
   cin >> x;
   cout << "0\n";
   for (ll k = 2; k <= x; k++) {
      ll n = k * k;
      cout << n * (n - 1) / 2 - 4 * (k - 1) * (k - 2) << "\n";
   }
   return 0;
}
