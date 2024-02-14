//10:56,11:58
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 0x3f3f3f3f;
int d[21][21];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1;i <= n;++i)
    for (int j = 1;j <= n;++j) {
      cin >> d[i][j];
    }

  int ans = 0;
  
  for (int i = 1;i < n;++i)
    for (int j = i + 1;j <= n;++j) {
      ans += d[i][j];

      for (int k = 1;k <= n;++k) {
        if (k == i || k == j) continue; //우회로 아님.
        if (d[i][j] < d[i][k] + d[k][j]) continue; // 직접 간선이 최단 거리

        if (d[i][j] > d[i][k] + d[k][j]) { // 잘못된 최단 거리 
          cout << -1;

          return 0;
        }

        // 우회로 존재 == 간선 제거 가능
        ans -= d[i][j];
        break;
      }
    }

  cout << ans;
}