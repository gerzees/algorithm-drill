//09:33,09:50
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int D[101][101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int s, t, cost;
    cin >> s >> t >> cost;

    if (D[s][t] == 0) {
      D[s][t] = cost;
      continue;
    }

    D[s][t] = min(cost, D[s][t]);
  }

  for (int k = 1;k <= n; ++k) {
    for (int s = 1; s <= n; ++s) {
      for (int t = 1;t <= n;++t) {
        if (s == t) continue;

        if (D[s][k] == 0 || D[k][t] == 0) continue;

        if (D[s][t] == 0)
          D[s][t] = D[s][k] + D[k][t];
        else
          D[s][t] = min(D[s][t], D[s][k] + D[k][t]);
      }
    }
  }

  for (int s = 1;s <= n;++s) {
    for (int t = 1;t <= n;++t) {
      cout << D[s][t] << ' ';
    }
    cout << '\n';
  }
}