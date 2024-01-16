//10:40, 11:33
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

char campus[601][601];
vector<bool> vis(601 * 601);
int N, M;
const char EMPTY = 'O';
const char WALL = 'X';
const char DOYEON = 'I';
const char PERSON = 'P';
const string NO_MEET = "TT";
int cntMeet;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

void bfs(const pair<int, int>& root) {
  queue<pair<int, int>> q;
  q.push(root);
  vis[root.X * M + root.Y] = true;

  while (!q.empty()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();

    if (campus[x][y] == PERSON) ++cntMeet;

    for (int i = 0;i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (campus[nx][ny] == WALL) continue;
      if (vis[nx * M + ny]) continue;

      q.push({ nx,ny });
      vis[nx * M + ny] = true;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    cin >> campus[i];
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0;j < M; ++j) {

      if (campus[i][j] == DOYEON) {
        bfs({ i,j });

        goto done;
      }
    }
  }

done:

  if (cntMeet == 0) {
    cout << NO_MEET;
    return 0;
  }

  cout << cntMeet;
}