// 9:50, 10:24
// 높이 h로 땅을 고르려면 N*M*h 만큼의 블럭 필요
// h로 만들기 위한 시간 계산.
#include<bits/stdc++.h>
using namespace std;

int N, M, B, tot, t, ansT, ansH;
int land[501][501];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> B;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> land[i][j];
      tot += land[i][j];
    }
  }

  ansH = 0;
  ansT = 2 * tot;

  tot += B;

  for (int h = 1; h <= tot / (N * M); ++h) {
    t = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        t += h > land[i][j] ? h - land[i][j] : 2 * (land[i][j] - h);
      }
    }

    if (t <= ansT) {
      ansH = h;
      ansT = t;
    }
  }

  cout << ansT << ' ' << ansH;
}