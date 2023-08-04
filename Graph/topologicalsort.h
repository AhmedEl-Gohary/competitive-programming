#include <bits/stdc++.h>
using namespace std;

struct topsort {
    int n;
    vector<vector<int>> g;
    vector<int> indeg;

    topsort() {}

    topsort(int _n) {
        n = _n;
        g.resize(n);
        indeg.resize(n);
    }

    void addEdge(int u, int v) {
        g[u].push_back(v);
        indeg[v]++;
    }

    // returns an empty vector if there is no order
    vector<int> order() {
        vector<int> ans, cur;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) cur.push_back(i);
        }
        while (!cur.empty()) {
            int v = cur.back();
            cur.pop_back();
            ans.push_back(v);
            for (int u : g[v]) {
                if (--indeg[u] == 0) cur.push_back(u);
            }
        }
        if (ans.size() < n) ans.clear();
        return ans;
    }

    vector<int> minorder() {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<>> cur;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) cur.push(i);
        }
        while (!cur.empty()) {
            int v = cur.top();
            cur.pop();
            ans.push_back(v);
            for (int u : g[v]) {
                if (--indeg[u] == 0) cur.push(u);
            }
        }
        if (ans.size() < n) ans.clear();
        return ans;
    }

    vector<int> maxorder() {
        vector<int> ans;
        priority_queue<int> cur;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) cur.push(i);
        }
        while (!cur.empty()) {
            int v = cur.top();
            cur.pop();
            ans.push_back(v);
            for (int u : g[v]) {
                if (--indeg[u] == 0) cur.push(u);
            }
        }
        if (ans.size() < n) ans.clear();
        return ans;
    }
};
