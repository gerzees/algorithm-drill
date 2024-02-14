//07:58,08:38
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 0x3f3f3f3f;
int d[201][201];
int nxt[201][201];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1;i <= n;++i) {
    fill(d[i], d[i] + 1 + n, INF);
    d[i][i] = 0;
  }

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    d[v][u] = w;
    d[u][v] = w;

    nxt[u][v] = v;
    nxt[v][u] = u;
  }

  for (int k = 1; k <= n;++k)
    for (int i = 1;i < n;++i)
      for (int j = i+1;j <= n;++j) {
        if (d[i][j] <= d[i][k] + d[k][j]) continue;

        d[i][j] = d[i][k] + d[k][j];
        d[j][i] = d[i][j];
        nxt[i][j] = nxt[i][k];
        nxt[j][i] = nxt[j][k];
      }

  for (int i = 1;i <= n;++i) {
    for (int j = 1;j <= n;++j) {
      if (i == j) cout << "- ";
      else cout << nxt[i][j] << ' ';
    }
    cout << '\n';
  }
}