#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int TC;
int N;
int M;
int W;
int dist[501][501];
vector<string> results;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> TC;
  results.reserve(TC);

  while (TC--) {
    // 입력
    cin >> N >> M >> W;

    for (int i = 1; i <= N; ++i) {
      fill(*(dist + i) + 1, *(dist + i) + N + 1, 1e5);
    }

    int S, E, T;

    while (M--) {
      cin >> S >> E >> T;

      if (dist[S][E] > T) {
        dist[S][E] = T;
        dist[E][S] = T;
      }
    }

    while (W--) {
      cin >> S >> E >> T;

      if (dist[S][E] > -T) {
        dist[S][E] = -T;
      }
    }

    // 처리
    bool yes = false;

    for (int i = 1; i <= N && yes == false; ++i) {
      for (int s = 1; s <= N && yes == false; ++s) {
        for (int e = 1; e <= N && yes == false; ++e) {
          dist[s][e] = min(dist[s][e], dist[s][i] + dist[i][e]);
          if (s == e && dist[s][e] < 0) {
            yes = true;
          }
        }
      }
    }

    results.push_back(yes ? "YES" : "NO");
  }

  //출력
  for (const string& result : results) {
    cout << result << '\n';
  }
}