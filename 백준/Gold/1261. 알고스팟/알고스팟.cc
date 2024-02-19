//07:49,09:28
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int d[101][101];
bool chk[101][101];
string maze[101];
// 상,하,좌,우
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;

  for (int i = 0;i < n;++i)
    fill(d[i], d[i] + m, INF);

  for (int i = 0;i < n;++i)
    cin >> maze[i];

  //{거리, x,y}
  priority_queue<
    tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>
  > pq;

  d[0][0] = 0;
  pq.push({ d[0][0],0,0 });

  while (!pq.empty()) {
    int dist;
    pair<int, int> cur;
    tie(dist, cur.X, cur.Y) = pq.top();pq.pop();

    if (dist != d[cur.X][cur.Y]) continue;

    if (cur.X == n - 1 && cur.Y == m - 1) break;

    chk[cur.X][cur.Y] = true;

    for (int i = 0;i < 4;++i) {
      pair<int, int> nxt = { cur.X + dx[i],cur.Y + dy[i] };

      if (nxt.X < 0 || nxt.X >= n || nxt.Y < 0 || nxt.Y >= m) continue;

      if (chk[nxt.X][nxt.Y]) continue;

      int nxt_dist = dist;
      if (maze[nxt.X][nxt.Y] != '0') {
        ++nxt_dist;
      }

      if (nxt_dist >= d[nxt.X][nxt.Y]) continue;

      d[nxt.X][nxt.Y] = nxt_dist;
      pq.push({ d[nxt.X][nxt.Y],nxt.X,nxt.Y });
    }
  }

  cout << d[n - 1][m - 1];
}