#include <bits/stdc++.h>
using namespace std;

template <class T> struct SegTree {
    int n;
    vector<T> tree;

    const T unit = 0;
    T f(T a, T b) {
        return a + b;
    }

    SegTree() {}

    SegTree(int _n) {
        n = 1 << (bit_width(unsigned(_n)));
        tree.assign(2 * n, unit);
    }

    T query(int l, int r) {
        l += n, r += n;
        T ans = 0;
        while (l <= r) {
            if (l & 1) ans = f(ans, tree[l++]);
            if (r % 2 == 0) ans = f(ans, tree[r--]);
            l /= 2, r /= 2;
        }
        return ans;
    }

    void update(int k, T x) {
        k += n;
        tree[k] = x;
        for (k /= 2; k >= 1; k /= 2) {
            tree[k] = f(tree[2 * k], tree[2 * k + 1]);
        }
    }
};
