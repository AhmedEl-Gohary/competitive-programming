#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, size;

    DSU() {}

    DSU(int _n) {
        n = _n;
        parent = vector(n, 0);
        size = vector(n, 1);
        iota(begin(parent), end(parent), 0);
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int sz(int v) {
        return size[find(v)];
    }

    vector<vector<int>> comp() {
        vector<int> par(n), compSize(n);
        for (int i = 0; i < n; i++) {
            par[i] = find(i);
            compSize[par[i]]++;
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            ans[par[i]].reserve(compSize[i]);
        }
        for (int i = 0; i < n; i++) {
            ans[par[i]].push_back(i);
        }
        auto pred = [&](const vector<int> &v) {
            return v.empty();
        };
        ans.erase(remove_if(begin(ans), end(ans), pred), end(ans));
        return ans;
    }
};
