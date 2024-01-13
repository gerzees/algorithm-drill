//9:58, 10:51
#include<bits/stdc++.h>
using namespace std;

int K, V, E, u, v;
vector<int> adj[20'001]; //메모리 터지면 지역변수로.
vector<int> bipart(20'001); // -1:모름, 0:분할1, 1:분할2

bool canBipartite(int st) {// 이분 그래프 될 수 없으면 false 반환, 될 수 있으면 true
  queue<int> q;
  q.push(st);
  bipart[st] = 1;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int nxt : adj[cur]) {
      if (bipart[nxt] == bipart[cur]) return false;

      if (bipart[nxt] != -1) continue;

      q.push(nxt);
      bipart[nxt] = (int)!bipart[cur];
    }
  }

  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K;

  while (K--) {
    fill(bipart.begin(), bipart.end(), -1);
    for (int i = 1;i <= V;++i) {
      adj[i].clear();
    }

    cin >> V >> E;

    while (E--) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      bipart[u] = -1;
      bipart[v] = -1;
    }

    bool bBipartite = true;
    for (int i = 1;i <= V;++i) {
      if (bipart[i] != -1 || canBipartite(i)) continue;

      bBipartite = false;
      break;
    }

    cout << (bBipartite ? "YES" : "NO") << '\n';
  }
}