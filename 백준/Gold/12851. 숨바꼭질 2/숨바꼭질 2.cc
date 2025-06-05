#include <bits/stdc++.h>

using namespace std;

/// <summary>
/// 수빈이의 위치
/// </summary>
int N;
/// <summary>
/// 동생의 위치
/// </summary>
int K;

int time_pos[100'001];
int time_shortest = -1;
int cnt_shortest;

queue<int> Q;

int (*nxt_pos[3])(int) = {
[](int cur)->int {return cur + 1; },
[](int cur)->int {return cur - 1; },
[](int cur)->int {return cur * 2; }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 입력
  cin >> N >> K;

  //처리
  Q.push(N);

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    // 동생 찾음
    if (cur == K) {
      if (time_shortest < 0) {
        time_shortest = time_pos[cur];
      }

      ++cnt_shortest;
    }

    for (int i = 0; i < 3; ++i) {
      int nxt = nxt_pos[i](cur);

      // 범위 벗어나면 가지 않는다
      if (nxt < 0 || nxt > 100'000) {
        continue;
      }

      // 시작 위치 or 다른 방법으로 더 짧은 시간으로 방문할 수 있다면
      // 가지 않는다
      if (nxt == N
        || time_pos[nxt] > 0 && time_pos[nxt] < time_pos[cur] + 1) {
        continue;
      }

      // 동생 찾은 후에는
      // 가장 빠른 시간 초과하는 길은 가지 않는다

      if (time_shortest >= 0 && time_shortest < time_pos[cur] + 1) {
        continue;
      }

      Q.push(nxt);
      time_pos[nxt] = time_pos[cur] + 1;
    }
  }

  // 출력
  cout << time_shortest << '\n' << cnt_shortest;
}