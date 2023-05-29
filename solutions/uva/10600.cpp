#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
   vector<int> parent, size;
   DSU(int n) {
      parent = vector(n, -1);
      size = vector(n, 0);
   }

   void make_set(int v) {
      parent[v] = v;
      size[v] = 1;
   }

   int get(int v) {
      if (parent[v] < 0) make_set(v);
      if (v == parent[v]) return v;
      return parent[v] = get(parent[v]);
   }

   bool same_set(int a, int b) {
      return get(a) == get(b);
   }

   bool unite(int a, int b) {
      a = get(a);
      b = get(b);
      if (a == b) return false;
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      size[a] += size[b];
      return true;
   }

   int sz(int v) {
      return size[get(v)];
   }

};
struct edge {
   int u, v, w, idx;
   bool del;
   edge() = default;
   edge(int u, int v, int w, int idx) : u(u), v(v), w(w), idx(idx), del(false) {}
   bool operator < (const edge& e) const {
      return w > e.w;
   }
};

pair<int, vector<edge>> getMST(vector<edge>& a, int n) {
   priority_queue<edge> pq;
   for (const auto& e : a) {
      if (!e.del) {
         pq.emplace(e);
      }
   }
   DSU dsu(n);
   int cost = 0;
   vector<edge> mst;
   while (!pq.empty()) {
      auto [u, v, w, i, del] = pq.top();
      pq.pop();
      if (dsu.unite(u, v)) {
         cost += w;
         mst.emplace_back(u, v, w, i);
      }
   }
   if (mst.size() < n - 1) {
      return {1e9, vector<edge>()};
   }
   return {cost, mst};
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
      int n, m;
      cin >> n >> m;
      vector<edge> a;
      for (int i = 0; i < m; i++) {
         int u, v, w;
         cin >> u >> v >> w;
         u--, v--;
         a.emplace_back(u, v, w, i);
      }
      auto [cost1, mst] = getMST(a, n);
      int cost2 = 1e9;
      for (int i = 0; i < n - 1; i++) {
         a[mst[i].idx].del = true;
         auto [cost, mst2] = getMST(a, n);
         cost2 = min(cost2, cost);
         a[mst[i].idx].del = false;
      }
      cout << cost1 << " " << cost2 << "\n";
   }
   return 0;
}