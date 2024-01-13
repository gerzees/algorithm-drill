//12:05, 12:23
#include<bits/stdc++.h>
using namespace std;
/*
* 각 지점에서 목표지점까지 거리 == 목표지점에서 각 지점까지 거리
*/

int n, m;
int board[1000][1000];
int dis[1000][1000];
const int dx[] = { 0,-1,0,1 };
const int dy[] = { 1,0,-1,0 };

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  queue<pair<int, int>> q;

  for (int i = 0;i < n; ++i) {
    fill(dis[i], dis[i] + m, -1);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];

      switch (board[i][j]) {
      case 2:
        q.push({ i,j });
        [[fallthrough]];
      case 0:
        dis[i][j] = 0;
        break;
      }
    }
  }

  while (!q.empty()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();

    for (int i = 0;i < 4;++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;

      if (dis[nx][ny] != -1)
        continue;

      q.push({ nx,ny });
      dis[nx][ny] = dis[x][y] + 1;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << dis[i][j] << ' ';
    }

    cout << '\n';
  }
}