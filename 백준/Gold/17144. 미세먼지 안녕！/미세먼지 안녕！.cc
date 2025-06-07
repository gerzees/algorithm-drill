#include<bits/stdc++.h>
using namespace std;
int R, C, T;
int A[51][51][2];
int cleaner;
int total_dirt;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

inline bool isOut(int r, int c) {
  return r < 0 || r >= R || c < 0 || c >= C;
}
inline bool isOutUpperCleaner(int r, int c) {
  return r < 0 || r >= cleaner || c < 0 || c >= C;
}
inline bool isOutLowerCleaner(int r, int c) {
  return r < cleaner || r >= R || c < 0 || c >= C;
}
void diffuse() {
  // 이전 확산 완료 상태로 갱신
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      A[r][c][0] = A[r][c][1];
    }
  }

  // 확산
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      for (int i = 0; i < 4; ++i) {
        int diffused_r = r + dr[i];
        int diffused_c = c + dc[i];

        if (isOut(diffused_r, diffused_c)) {
          continue;
        }

        if (A[diffused_r][diffused_c][0] == -1) {
          continue;
        }

        A[r][c][1] -= A[r][c][0] / 5;
        A[diffused_r][diffused_c][1] += A[r][c][0] / 5;
      }
    }
  }
}

void clean() {
  // 반시계방향 순환(윗 구역
  int start_r = cleaner - 1;
  int start_c = 0;
  int cur_r = start_r;
  int cur_c = start_c;
  for (int i = 0; i < 4; ++i) {
    int nxt_r = cur_r + dr[i];
    int nxt_c = cur_c + dc[i];
    while (isOutUpperCleaner(nxt_r, nxt_c) == false) {
      if (cur_r == start_r && cur_c == start_c) {
        // 청정기 먼지 제거
        total_dirt -= A[nxt_r][nxt_c][1];
      }
      else if (nxt_r != start_r || nxt_c != start_c) {
        // 먼지 이동
        A[cur_r][cur_c][1] = A[nxt_r][nxt_c][1];
      }
      else {
        // 청정 공기
        A[cur_r][cur_c][1] = 0;
      }

      cur_r = nxt_r;
      cur_c = nxt_c;
      nxt_r = cur_r + dr[i];
      nxt_c = cur_c + dc[i];
    }
  }
  // 시계방향 순환(아랫 구역
  start_r = cleaner;
  start_c = 0;
  cur_r = start_r;
  cur_c = start_c;
  for (int i = 0; i < 4; ++i) {
    int nxt_r = cur_r - dr[i];
    int nxt_c = cur_c + dc[i];
    while (isOutLowerCleaner(nxt_r, nxt_c) == false) {
      if (cur_r == start_r && cur_c == start_c) {
        // 청정기 먼지 제거
        total_dirt -= A[nxt_r][nxt_c][1];
      }
      else if (nxt_r != start_r || nxt_c != start_c) {
        // 먼지 이동
        A[cur_r][cur_c][1] = A[nxt_r][nxt_c][1];
      }
      else {
        // 청정 공기
        A[cur_r][cur_c][1] = 0;
      }

      cur_r = nxt_r;
      cur_c = nxt_c;
      nxt_r = cur_r - dr[i];
      nxt_c = cur_c + dc[i];
    }
  }
}
void display() {
  cout << '\n';
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      if (A[r][c][1] == -1) {
        cout << 'C' << ' ';
        continue;
      }
      cout << A[r][c][1] << ' ';
    }
    cout << '\n';
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C >> T;

  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      int dirt;
      cin >> dirt;
      A[r][c][1] = dirt;

      if (dirt == -1) {
        cleaner = r;
        continue;
      }

      total_dirt += dirt;
    }
  }


  while (T--) {
    // 먼지 확산
    diffuse();
    //display();
    // 공기청정기 작동
    clean();
    // 상태 표시
    //display();
  }

  cout << total_dirt;
}