#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
      int n, k;
      cin >> n >> k;
      vector<int> a(n);
      map<int, stack<int>> mp;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
      }
      set<int> s(begin(a), end(a));
      for (auto& x : s) {
         mp[x].push(n);
      }
      for (int i = n - 1; i >= 0; i--) {
         mp[a[i]].push(i);
      }
      int ans = 0;
      s.clear();
      set<pair<int, int>> maxPos;
      for (int i = 0; i < n; i++) {
         if (!s.count(a[i])) {
            mp[a[i]].pop();
            if (s.size() == k) {
               auto [mx, val] = *rbegin(maxPos);
               maxPos.erase(prev(end(maxPos)));
               s.erase(val);
            }
            s.insert(a[i]);
            maxPos.emplace(mp[a[i]].top(), a[i]);
            ans++;
         } else {
            maxPos.erase({mp[a[i]].top(), a[i]});
            mp[a[i]].pop();
            maxPos.emplace(mp[a[i]].top(), a[i]);
         }
      }
      cout << ans << "\n";
   }
   return 0;
}

