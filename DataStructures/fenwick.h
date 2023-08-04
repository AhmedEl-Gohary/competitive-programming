#include <bits/stdc++.h>
using namespace std;

template <class T> struct fenwick {
    int n;
    vector<T> a, bit;

    fenwick() {}

    fenwick(int _n) {
        n = _n + 1;
        a = bit = vector<T>(n + 1);
    }

    void add(int idx, T delta) {
        a[idx] += delta;
        for (int i = idx; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    void set(int idx, T val) {
        add(idx, val - a[idx]);
    }

    T query(int idx) {
        T sum = 0;
        for (int i = idx; i >= 1; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
