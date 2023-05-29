// with path compression and union by size

struct DSU {
   vector<int> parent, size;

   DSU(int n) {
      parent = vector(n, 0);
      size = vector(n, 1);
      iota(begin(parent), end(parent), 0);
   }

   int get(int v) {
      if (v == parent[v]) return v;
      return parent[v] = get(parent[v]);
   }

   bool same_set(int a, int b) {
      return get(a) == get(b);
   }

   bool unite(int a, int b) {
      a = get(a), b = get(b);
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
