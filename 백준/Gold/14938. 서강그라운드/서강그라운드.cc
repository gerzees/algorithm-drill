//11:10,11:35
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[101][101];
int cnt_item[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, r;
  cin >> n >> m >> r;

  for (int i = 1; i <= n; ++i)
    cin >> cnt_item[i];

  for (int i = 1;i <= n; ++i)
    fill(d[i], d[i] + 1 + n, INF);

  for (int i = 1; i <= n; ++i) d[i][i] = 0;

  while (r--) {
    int a, b, l;
    cin >> a >> b >> l;

    if (l < d[a][b]) {
      d[a][b] = l;
      d[b][a] = l;
    }
  }

  for (int k = 1;k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = i + 1;j <= n; ++j)
        if (d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
          d[j][i] = d[i][j];
        }

  int ans = 0;
  for (int i = 1;i <= n; ++i) {
    int total = 0;
    for (int j = 1;j <= n;++j) {
      if (d[i][j] <= m) {
        total += cnt_item[j];
      }
    }

    if (ans < total)
      ans = total;
  }

  cout << ans;
}