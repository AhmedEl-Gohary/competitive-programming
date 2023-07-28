template <bool directed> struct BFS01 {
    int n;
    vector<vector<pair<int, int>>> g;
    BFS01() {}
    BFS01(int _n) {
        n = _n;
        g.resize(n + 1);
    }
    void addEdge(int u, int v, int w) {
        g[u].emplace_back(v, w);
        if (!directed) g[v].emplace_back(u, w);
    }
    vector<int> dist(const vector<int>& sources) {
        deque<int> q;
        vector<int> d(n + 1, 1e9);
        for (auto& u : sources) {
            q.push_back(u);
            d[u] = 0;
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            for (const auto& [u, w] : g[v]) {
                if (d[v] + w < d[u]) {
                    d[u] = d[v] + w;
                    if (w == 1) q.push_back(u);
                    else q.push_front(u);
                }
            }
        }
        return d;
    }
    int dist(int u, int v) {
        return dist({u})[v];
    }
};
