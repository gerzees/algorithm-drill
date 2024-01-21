//7:48, 7:57
#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[32'001];
int indegree[32'001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    ++indegree[b];
  }

  queue<int> q;

  for (int i = 1; i <= N; ++i)
    if (indegree[i] == 0) q.push(i);

  while (!q.empty()) {
    int cur = q.front(); q.pop();

    cout << cur << ' ';

    for (int nxt : adj[cur]) {
      --indegree[nxt];

      if (indegree[nxt] == 0) q.push(nxt);
    }
  }
}