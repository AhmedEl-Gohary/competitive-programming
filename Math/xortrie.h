#include <bits/stdc++.h>
using namespace std;

template <class T, int bits> struct xortrie {
    vector<array<int, 2>> trie = {{0, 0}};
    vector<int> cnt = {0};
    xortrie() {}
    void update(T val, int delta) {
        int node = 0;
        for (int i = bits - 1; i >= 0; i--) {
            int j = (val & (1 << i) ? 1 : 0);
            if (trie[node][j] == 0) {
                trie[node][j] = trie.size();
                trie.push_back({0, 0});
                cnt.push_back(0);
            }
            node = trie[node][j];
            cnt[node] += delta;
        }
    }
    void insert(T val) {
        update(val, 1);
    }
    void erase(T val) {
        update(val, -1);
    }
    T max(T val) {
        T ans = 0;
        int node = 0;
        for (int i = bits - 1; i >= 0; i--) {
            int j = (val & (1 << i) ? 0 : 1);
            if (trie[node][j] && cnt[trie[node][j]]) {
                ans |= (1ll << i);
                node = trie[node][j];
            } else {
                node = trie[node][j ^ 1];
            }
        }
        return ans;
    }
    T min(T val) {
        T ans = 0;
        int node = 0;
        for (int i = bits - 1; i >= 0; i--) {
            int j = (val & (1 << i) ? 1 : 0);
            if (trie[node][j] && cnt[trie[node][j]]) {
                node = trie[node][j];
            } else {
                ans |= (1ll << i);
                node = trie[node][j ^ 1];
            }
        }
        return ans;
    }
};
