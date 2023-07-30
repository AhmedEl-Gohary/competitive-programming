#include <bits/stdc++.h>
using namespace std;

template <class T> struct LCA {
    int n, LOG, curTime = 0;
    vector<vector<int>> up;
    vector<vector<T>> mx;
    vector<vector<pair<int, T>>> g;
    vector<int> depth, tin, tout;
    vector<T> distance;

    LCA() {}

    LCA(int _n) {
        n = _n + 1;
        LOG = __lg(_n) + 1;
        up = vector<vector<int>>(n, vector<int>(LOG));
        mx = vector<vector<T>>(n, vector<T>(LOG));
        g.resize(n);
        depth.resize(n);
        distance.resize(n);
        tin.resize(n);
        tout.resize(n);
    }

    void addEdge(int u, int v, T w) {
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    void dfs(int v, int p = -1, int curDepth = 0, int curDist = 0) {
        tin[v] = tout[v] = curTime++;
        depth[v] = curDepth;
        distance[v] = curDist;
        up[v][0] = p;
        for (int j = 1; j < LOG; j++) {
            if (up[v][j - 1] == -1) {
                up[v][j] = -1;
            } else {
                up[v][j] = up[up[v][j - 1]][j - 1];
                mx[v][j] = max(mx[v][j - 1], mx[up[v][j - 1]][j - 1]);
            }
        }
        for (const auto& [u, w] : g[v]) {
            if (u == p) continue;
            mx[u][0] = w;
            dfs(u, v, curDepth + 1, curDist + w);
            tout[u] = curTime++;
        }
    }

    void build(int root = 1) {
        dfs(root);
    }

    // return <kth ancestor, max edge on path>
    pair<int, T> ancestor(int v, int k) {
        T w = 0;
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                w = max(w, mx[v][j]);
                v = up[v][j];
            }
        }
        return make_pair(v, w);
    }

    // return <lca, max edge on path>
    pair<int, T> lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        auto level = ancestor(a, depth[a] - depth[b]);
        a = level.first;
        T w = level.second;
        if (a == b) return make_pair(a, w);
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                w = max(w, max(mx[a][j], mx[b][j]));
                a = up[a][j];
                b = up[b][j];
            }
        }
        return make_pair(up[a][0], max(w, max(mx[a][0], mx[b][0])));
    }

    T dist(int a, int b) {
        return distance[a] + distance[b] - 2 * distance[lca(a, b).first];
    }

    // return if a is an ancestor of b
    bool isAncestor(int a, int b) {
        return tin[a] <= tin[b] && tin[b] <= tout[a];
    }

    // find the kth node on path from a to b
    int findKthOnPath(int a, int b, int k) {
        int l = lca(a, b).first;
        int d = depth[a] + depth[b] - 2 * depth[l];
        if (d > k + 1) return -1;
        if (depth[a] - depth[l] >= k) return ancestor(a, k - 1).first;
        return ancestor(b, d - (k - 1)).first;
    }
};
