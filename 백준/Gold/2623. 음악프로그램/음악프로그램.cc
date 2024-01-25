//14:35, 14:53
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[1'001];
int order[1'000];
int indegree[1'001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  while (M--) {
    int cnt;
    cin >> cnt;

    for (int i = 0; i < cnt; ++i) {
      cin >> order[i];
    }

    for (int i = 0; i + 1 < cnt; ++i) {
      adj[order[i]].push_back(order[i + 1]);
      ++indegree[order[i + 1]];
    }
  }

  vector<int> ans;
  ans.reserve(N);
  queue<int> q;

  for (int i = 1; i <= N; ++i) {
    if (indegree[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front(); q.pop();
    ans.push_back(cur);

    for (int nxt : adj[cur]) {

      --indegree[nxt];
      if (indegree[nxt] == 0) q.push(nxt);
    }
  }

  if (ans.size() == N) {
    for (int singer : ans) {
      cout << singer << '\n';
    }
  }
  else {
    cout << 0;
  }
}