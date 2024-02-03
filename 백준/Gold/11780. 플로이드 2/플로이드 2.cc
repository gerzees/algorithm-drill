//10:28, 11:43
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int d[101][101];
// 비용 최대. 9'900'000
// 총 도시 100개, 버스 탄 횟수 최대 99회, 버스비 최대 100'000
// 99% 메모리 초과.
int INF = 10'000'000;
int nxt[101][101];
int route[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i)
    fill(d[i], d[i] + n + 1, INF);

  for (int i = 1;i <= n; ++i)
    d[i][i] = 0;

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;

    if (c < d[a][b]) {
      d[a][b] = c;
      nxt[a][b] = b;
    }
  }

  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1;j <= n;++j)
        if (d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
          nxt[i][j] = nxt[i][k];
        }

  for (int i = 1;i <= n;++i) {
    for (int j = 1; j <= n; ++j) {
      if (d[i][j] == INF) {
        cout << 0 << ' ';
      
        continue;
      }

      cout << d[i][j] << ' ';
    }
    cout << '\n';
  }


  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (d[i][j] == 0 ||d[i][j] == INF) {
        cout << 0 << '\n';

        continue;
      }

      int unused = 0;
      int cur = i;

      while (true) {
        route[unused++] = cur;

        if (cur == j) break;

        cur = nxt[cur][j];
      }

      cout << unused << ' ';

      for(int i=0; i<unused; ++i){
        cout << route[i] << ' ';
      }

      cout << '\n';
    }
  }
}