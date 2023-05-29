#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   if (k == 1) {
      for (int i = 0; i < n; i++) {
         cout << 0 << " ";
      }
      return 0;
   }
   if (k == 2) {
      for (int i = 0; i < n - 1; i++) {
         cout << abs(a[i] - a[i + 1]) << " ";
      }
      return 0;
   }
   set<pair<int, int>> ls, rs;
   ll lsize = (k + 1) / 2;
   ll sumLeft = 0, sumRight = 0;
   vector<pair<int, int>> b(k);
   for (int i = 0; i < k; i++) {
      b[i] = {a[i], i};
   }
   sort(begin(b), end(b));
   for (int i = 0; i < lsize; i++) {
      sumLeft += b[i].first;
      ls.emplace(b[i]);
   }
   for (int i = lsize; i < k; i++) {
      sumRight += b[i].first;
      rs.emplace(b[i]);
   }
   ll median = rbegin(ls)->first;
   cout << (median * (ll) ls.size() - sumLeft) + (sumRight - median * (ll) rs.size()) << " ";
   for (int i = k; i < n; i++) {
      if (ls.count({a[i - k], i - k})) {
         sumLeft -= a[i - k];
         ls.erase({a[i - k], i - k});
      } else {
         sumRight -= a[i - k];
         rs.erase({a[i - k], i - k});
      }
      if (a[i] <= rbegin(ls)->first) {
         sumLeft += a[i];
         ls.emplace(a[i], i);
      } else {
         sumRight += a[i];
         rs.emplace(a[i], i);
      }
      while (ls.size() > lsize) {
         sumLeft -= rbegin(ls)->first;
         sumRight += rbegin(ls)->first;
         rs.emplace(*rbegin(ls));
         ls.erase(prev(end(ls)));
      }
      while (ls.size() < lsize) {
         sumLeft += begin(rs)->first;
         sumRight -= begin(rs)->first;
         ls.emplace(*begin(rs));
         rs.erase(begin(rs));
      }
      median = rbegin(ls)->first;
      cout << (median * (ll) ls.size() - sumLeft) + (sumRight - median * (ll) rs.size()) << " ";
   }
   return 0;
}
