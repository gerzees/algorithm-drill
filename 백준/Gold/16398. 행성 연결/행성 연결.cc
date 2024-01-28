//20:55,21:46
#include <bits/stdc++.h>

using namespace std;

long long total;
int  N, M;
int adj[1001][1001];
int cnt;
vector<bool> is_connected(1001);
priority_queue<pair< int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0;i < N;++i) {
    for (int j = 0;j < N;++j) {
      cin >> adj[i][j];
    }
  }

  is_connected[0] = true;
  for (int i = 1; i < N; ++i) {
    pq.push({ adj[0][i],i });
  }

  while (cnt < N - 1) {
    int cost, added;
    tie(cost, added) = pq.top(); pq.pop();

    if (is_connected[added]) continue;

    ++cnt;
    total += cost;

    is_connected[added] = true;
    for (int i = 0; i < N; ++i) {
      if (is_connected[i]) continue;

      pq.push({ adj[added][i],i });
    }
  }

  cout << total;
}