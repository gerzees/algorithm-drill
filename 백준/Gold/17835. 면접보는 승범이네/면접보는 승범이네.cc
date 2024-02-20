//08:26,11:13
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
long long d[100'001];
tuple<int, int, int> edge[500'000];
// {거리,정점번호} 
vector<pair<long long, int>> adj[100'001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  fill(d, d + 1 + n, INF);

  for (int i = 0;i < m;++i) {
    int u, v, c;
    cin >> u >> v >> c;
    edge[i] = { u,v,c };
  }

  for (int i = 0;i < k;++i) {
    int interview_city;
    cin >> interview_city;
    d[interview_city] = 0;
  }

  for (int i = 0;i < m;++i) {
    int u, v, c;
    tie(u, v, c) = edge[i];
    if (d[u] == 0 && d[v] == 0) continue;
    if (d[u] == 0) adj[v].push_back({ c,0 });
    else if (d[v] == 0) adj[0].push_back({ c,u });
    else adj[v].push_back({ c,u });
  }


  priority_queue<
    pair<long long, int>,
    vector<pair<long long, int>>,
    greater<pair<long long, int>>
  > pq;
  d[0] = 0;
  pq.push({ d[0],0 });

  while (!pq.empty()) {
    int cur;
    long long w;
    tie(w, cur) = pq.top(); pq.pop();

    if (w != d[cur]) continue;

    for (auto& [dw, nxt] : adj[cur]) {
      if (w + dw >= d[nxt]) continue;

      d[nxt] = w + dw;
      pq.push({ d[nxt],nxt });
    }
  }

  long long max_dist = d[1];
  int max_dist_city = 1;
  
  for (int i = 2;i <= n;++i) {
    if (d[i] <= max_dist) continue;

    max_dist = d[i];
    max_dist_city = i;
  }

  cout << max_dist_city << '\n' << max_dist;
}