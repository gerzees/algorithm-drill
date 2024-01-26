//
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[32'001];
int indegree[32'001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  while (M--) {
    int a, b;
    // order(edge): a -> b
    cin >> a >> b;

    adj[a].push_back(b);
    ++indegree[b];
  }

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 1; i <= N; ++i) {
    if (!indegree[i]) pq.push(i);
  }

  while (!pq.empty()) {
    int cur = pq.top(); pq.pop();

    cout << cur << ' ';

    for (int nxt : adj[cur]) {
      --indegree[nxt];

      if (!indegree[nxt]) pq.push(nxt);
    }
  }
}