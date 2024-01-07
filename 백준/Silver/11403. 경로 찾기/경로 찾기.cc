//18:05, 18:30
#include<bits/stdc++.h>
using namespace std;

int adj[101][101];
vector<bool> vis(101, false);
int N;

void bfs(int start) {
  fill(vis.begin(), vis.end(), false);

  queue<int> q;

  for (int i = 0;i < N;++i) {
    if (adj[start][i] == 0) continue;

    q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int i = 0; i < N; ++i) {
      if (adj[cur][i] == 0) continue;
      if (adj[start][i]) continue;

      q.push(i);
      adj[start][i] = 1;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0;i < N;++i) {
    for (int j = 0;j < N;++j) {
      cin >> adj[i][j];
    }
  }

  for (int i = 0;i < N;++i) {
    bfs(i);
  }

  for (int i = 0;i < N;++i) {
    for (int j = 0;j < N;++j) {
      cout << adj[i][j] << ' ';
    }
    cout << '\n';
  }
}