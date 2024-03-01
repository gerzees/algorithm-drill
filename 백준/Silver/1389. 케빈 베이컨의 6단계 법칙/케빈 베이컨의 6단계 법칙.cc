//14:06,14:27
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 0x3f3f3f3f;
int d[101][101];
int kevin_bacon_num[101];
int n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1;i <= n;++i) {
    fill(d[i], d[i] + 1 + n, INF);
    d[i][i] = 0;
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    d[a][b] = 1;
    d[b][a] = 1;
  }

  for (int k = 1;k <= n;++k)
    for (int i = 1;i <= n;++i)
      for (int j = 1; j <= n; ++j)
        if (d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
        }

  for (int i = 1;i <= n; ++i)
    for (int j = 1;j <= n;++j) {
      if (i == j) continue;

      kevin_bacon_num[i] += d[i][j];
    }

  int* min_p = kevin_bacon_num + 1;
  for (int* p = kevin_bacon_num + 2; p <= kevin_bacon_num + n; ++p) {
    if (*min_p > *p) {
      min_p = p;
    }
  }

  cout << min_p - kevin_bacon_num;
}