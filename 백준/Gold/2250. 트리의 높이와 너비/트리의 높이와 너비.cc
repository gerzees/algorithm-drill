//21:19, 22:19
#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> children[10'001];
int par[10'001];
vector<pair<int, int>> columns(10'001, { 10'001,0 });
int col = 0;

void inorder(int node, int level) {
  auto [l_child, r_child] = children[node];

  if (l_child != 0) {
    inorder(l_child, level + 1);
  }

  // node 방문 -> 방문 순서 증가
  // 방문 순서 == 열 번호
  ++col;

  if (col < columns[level].first) {
    columns[level].first = col;
  }
  if (col > columns[level].second) {
    columns[level].second = col;
  }

  if (r_child != 0) {
    inorder(r_child, level + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    int node, l_child, r_child;
    cin >> node >> l_child >> r_child;

    if (l_child != -1) {
      children[node].first = l_child;
      par[l_child] = node;
    }

    if (r_child != -1) {
      children[node].second = r_child;
      par[r_child] = node;
    }
  }

  int cur = 1;

  while (par[cur] != 0) {
    cur = par[cur];
  }

  int root = cur;

  inorder(root, 1);

  int l = 0;
  int w = 0;

  for (int i = 1; i <= N; ++i) {
    if (w < columns[i].second - columns[i].first + 1) {
      l = i;
      w = columns[i].second - columns[i].first + 1;
    }
  }

  cout << l << ' ' << w;
}