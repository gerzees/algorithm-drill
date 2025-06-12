#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int paper[101][101];
int melted[101][101];
vector<bool> visited[101];
int n, m;

bool no_cheeze() {
  bool all_melted = true;

  for (int r = 0; r < n; ++r) {

    for (int c = 0; c < m; ++c) {

      if (paper[r][c] - melted[r][c] > 0) {
        all_melted = false;
      }
      else if (paper[r][c] > 0) {
        paper[r][c] = 0;
      }

      melted[r][c] = 0;
    }
  }

  return all_melted;
}

int dr[4] = { 0,-1,0,1 };
int dc[4] = { 1,0,-1,0 };
inline bool out_paper(const pii& pos) {
  return pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= m;
}
void melt() {
  for (int r = 0; r < n; ++r) {
    fill(visited[r].begin(), visited[r].end(), false);
  }

  queue<pii> q;
  q.push({ 0,0 });
  visited[0][0] = true;
  while (q.empty() == false) {
    pii& cur = q.front();
    q.pop();

    // 다음 외부 공기 q에 추가 & 녹는 양 계산
    for (int i = 0; i < 4; ++i) {
      pii nxt{ cur.first + dr[i],cur.second + dc[i] };

      if (out_paper(nxt)) {
        continue;
      }

      ++melted[nxt.first][nxt.second];

      if (visited[nxt.first][nxt.second]) {
        continue;
      }

      if (paper[nxt.first][nxt.second]) {
        continue;
      }

      visited[nxt.first][nxt.second] = true;
      q.push(nxt);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int r = 0; r < n; ++r) {
    visited[r].resize(m);
  }

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      bool cheeze;
      cin >> cheeze;
      if (cheeze) {
        paper[r][c] = 2;
      }
    }
  }

  int time = 0;
  while (true) {
    // 치즈 다 녹았는지 확인
    if (no_cheeze()) {
      break;
    }
    // 시간 흐름
    ++time;
    // 치즈 녹음
    melt();
  }

  cout << time;
}