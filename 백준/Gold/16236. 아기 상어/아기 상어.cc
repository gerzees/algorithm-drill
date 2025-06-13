#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int n;
int baby_shark_size = 2;
int baby_shark_cnt_eat;
pii baby_shark_pos;
int cnt_fish[7];
int space[21][21];
int dist[21][21];
int help_time;

bool need_mom_shark_help() {
  for (int size = 1; size < baby_shark_size && size < 7; ++size) {
    if (cnt_fish[size]) {
      return false;
    }
  }

  return true;
}

int dr[4] = { -1,0,0,1 };
int dc[4] = { 0,-1,1,0 };

int baby_shark_eat_fish() {
  for (int i = 0; i < n; ++i) {
    fill(dist[i], dist[i] + n, -1);
  }
  queue<pii> q;
  q.push(baby_shark_pos);
  dist[baby_shark_pos.first][baby_shark_pos.second] = 0;
  int fish_dist = 500;
  pii fish_pos(22, 22);
  while (q.empty() == false) {
    pii cur = q.front();
    q.pop();

    // 먹을 물고기 거리 이상 진행x
    if (
      dist[cur.first][cur.second] >= fish_dist) {
      continue;
    }

    for (int i = 0; i < 4; ++i) {
      pii nxt(cur.first + dr[i], cur.second + dc[i]);

      // 범위 밖 > 진행x
      if (nxt.first < 0 || nxt.second < 0 || nxt.first >= n || nxt.second >= n) {
        continue;
      }
      // 이미 방문 > 진행x
      if (dist[nxt.first][nxt.second] >= 0) {
        continue;
      }
      // 아기 상어보다 큰 물고기 존재 > 진행 x
      if (baby_shark_size < space[nxt.first][nxt.second]) {
        continue;
      }

      // 먹을 물고기 발견 
      if (space[nxt.first][nxt.second] > 0 && baby_shark_size > space[nxt.first][nxt.second]) {
        if (fish_pos.first > nxt.first
          || fish_pos.first == nxt.first && fish_pos.second > nxt.second) {
          fish_pos = nxt;
          fish_dist = dist[cur.first][cur.second] + 1;
        }
      }

      dist[nxt.first][nxt.second] = dist[cur.first][cur.second] + 1;
      q.push(nxt);
    }
  }

  // 먹을 물고기 없음(도달 불가)
  if (fish_pos.first > n) {
    return -1;
  }

  // 물고기 먹음
  // 0. 물고기 크기 증가
  if (++baby_shark_cnt_eat == baby_shark_size) {
    baby_shark_cnt_eat = 0;
    ++baby_shark_size;
  }
  // 1. 물고기 수 정산
  --cnt_fish[space[fish_pos.first][fish_pos.second]];
  // 2. 물고기 지우기
  space[fish_pos.first][fish_pos.second] = 0;
  // 3. 아기 상어의 다음 위치
  baby_shark_pos = fish_pos;

  return fish_dist;// 먹은 물고기까지 거리
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> space[i][j];
      if (space[i][j] == 9) {
        space[i][j] = 0;
        baby_shark_pos = pii(i, j);
      }
      else if (space[i][j] != 0) {
        ++cnt_fish[space[i][j]];
      }

    }
  }

  while (true) {
    if (need_mom_shark_help()) {
      break;
    }

    // 먹을 물고기 결정(거리 파악) > 걸린 시간과 다음 단계의 시작 지점 확보
    int eating_time = baby_shark_eat_fish();
    // 먹을 수 있는 물고기에 도달할 수 없음
    if (eating_time < 0) {
      break;
    }

    help_time += eating_time;
  }

  cout << help_time;
}