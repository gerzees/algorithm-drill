//16:14,16:49
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 0x3f3f3f3f;
int d[251][251];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  
  for (int i = 1;i <= n;++i) {
    fill(d[i], d[i] + 1 + n, INF);
    d[i][i] = 0;
  }

  while (m--) {
    int u, v, b;
    cin >> u >> v >> b;
    // 순방향 길이 있으면 거리 0, 역방향 길이 있으면 거리 1
    d[u][v] = 0;
    if (b) {//양방향 = 순방향 길
      d[v][u] = 0;
    }
    else {// 일방통행=역방향 길
      d[v][u] = 1;
    }
  }

  for(int k=1;k<=n;++k)
    for(int i=1;i<=n;++i)
      for (int j = 1;j <= n;++j) {
        if (d[i][j] <= d[i][k] + d[k][j]) continue;
        // 거쳐서 가는 길이 더 짧은 길이면 갱신
        d[i][j] = d[i][k] + d[k][j];
      }

  int k;
  cin >> k;

  while (k--) {
    int s, e;
    cin >> s >> e;
    cout << d[s][e] << '\n';
  }
}