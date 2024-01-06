//11:41, 12:03
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[501];
vector<int> dis(501, -1);
int n, m, ai, bi, ans;

void bfs() {
  queue<int> q;
  q.push(1);
  dis[1] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (dis[cur] >= 2)
      continue;
    for (int nxt : adj[cur]) {
      if (dis[nxt] >= 0) continue;

      q.push(nxt);
      ++ans;
      dis[nxt] = dis[cur] + 1;
    }
  }

}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (m--) {
    cin >> ai >> bi;
    adj[ai].push_back(bi);
    adj[bi].push_back(ai);
  }

  bfs();

  cout << ans;
}