#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct team {
   int id, solved;
   team() {}
   team(int id, int solved) : id(id), solved(solved) {}
   bool operator < (const team& t) const {
      return solved > t.solved;
   }
};

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n;
   cin >> n;
   vector<team> a(n);
   for (int i = 0; i < n; i++) {
      int id, m;
      cin >> id >> m;
      a[i] = {id, m};
   }
   stable_sort(begin(a), end(a));
   for (const auto& [id, solved] : a) {
      cout << id << " " << solved << "\n";
   }
   return 0;
}
