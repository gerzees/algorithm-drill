// 11:57, 12:45
#include<bits/stdc++.h>
using namespace std;

vector<int> squares;
int n;
int cnt[50'005];


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  squares.reserve(223);
  queue<int> q;

  for (int i = 1; i * i <= n; ++i) {
    squares.push_back(i * i);
    cnt[i * i] = 1;
    q.push(i * i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (cur == n) {
      cout << cnt[cur];
      return 0;
    }

    for (int square : squares) {
      if (cur + square > n) break;
      if (cnt[cur + square] != 0) continue;

      cnt[cur + square] = cnt[cur] + 1;
      q.push(cur + square);
    }
  }
}