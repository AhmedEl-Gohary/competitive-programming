#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n;
   cin >> n;
   vector<array<int, 3>> a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i][1] >> a[i][0] >> a[i][2];
   }
   sort(begin(a), end(a));
 
   map<ll, ll> dp;
   dp[0] = 0;
   ll ldp = 0;
   for (const auto& [r, l, reward] : a) {
      auto it = dp.lower_bound(l);
      --it;
      ldp = max(ldp, it->second + reward);
      dp[r] = ldp;
   }
   cout << ldp;
   return 0;
}
