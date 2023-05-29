#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;
string a[N];
int vis[N][N];
int n, m;
int dx[8] = {1, -1, 1, -1, 1, -1, 0, 0};
int dy[8] = {1, -1, -1, 1, 0, 0, 1, -1};
bool valid(int i, int j) {
   return i >= 0 && i < n && j >= 0 && j < m && a[i][j] != 'X';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
      cin >> n >> m;
      memset(vis, 0, sizeof(vis));
      int sx, sy, fx, fy;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
               sx = i, sy = j;
            }
            if (a[i][j] == 'F') {
               fx = i, fy = j;
            }
         }
      }
      queue<tuple<int, int, int>> q;
      q.emplace(sx, sy, 0);
      vis[sx][sy] = 255;
      int ans = -1;
      while (!q.empty()) {
         auto [vx, vy, d] = q.front();
         q.pop();
         if (vx == fx && vy == fy) {
            ans = d;
            break;
         }
         for (int i = 0; i < 8; i++) {
            int p = 1;
            while (true) {
               int r = vx + dx[i] * p;
               int c = vy + dy[i] * p;
               if (valid(r, c) && !(vis[r][c] & (1 << i))) {
                  if (vis[r][c] == 0) {
                     q.emplace(r, c, d + 1);
                  }
                  vis[r][c] |= (1 << i);
               } else {
                  break;
               }
               p++;
            }
         }
      }
      cout << ans << "\n";
   }
   return 0;
}

