#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> v;
vector<int> parent;
void mov(int a, int b) {
   vector<int> delay;
   int p = parent[a];
   while (!v[p].empty() && v[p].back() != a) {
      delay.push_back(v[p].back());
      parent[v[p].back()] = v[p].back();
      v[p].pop_back();
   }
   v[parent[b]].push_back(a);
   v[p].pop_back();
   parent[a] = parent[b];
   for (auto& x : delay) v[x].push_back(x);
}

void pile(int a, int b) {
   vector<int> delay;
   int p = parent[a];
   while (!v[p].empty() && v[p].back() != a) {
      delay.push_back(v[p].back());
      parent[v[p].back()] = parent[b];
      v[p].pop_back();
   }
   v[parent[b]].push_back(a);
   v[p].pop_back();
   parent[a] = parent[b];
   reverse(begin(delay), end(delay));
   for (auto& x : delay) v[parent[b]].push_back(x);
}

void onto(int b) {
   vector<int> delay;
   int p = parent[b];
   while (!v[p].empty() && v[p].back() != b) {
      delay.push_back(v[p].back());
      parent[v[p].back()] = v[p].back();
      v[p].pop_back();
   }
   for (auto& x : delay) v[x].push_back(x);
}


int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n;
   cin >> n;

   v = vector<vector<int>>(n);
   for (int i = 0; i < n; i++) v[i].push_back(i);
   parent = vector<int>(n);
   iota(begin(parent), end(parent), 0);

   int a, b;
   string qtA, qtB;
   while (cin >> qtA) {
      if (qtA == "quit") break;
      cin >> a >> qtB >> b;

      if (a == b || parent[a] == parent[b]) continue;
      if (qtB == "onto") onto(b);
      if (qtA == "move") mov(a, b);
      else pile(a, b);
   }

   for (int i = 0; i < n; i++) {
      cout << i << ":";
      for (auto& x : v[i]) {
         cout << x << " ";
      }
      cout << "\n";
   }
   return 0;
}
