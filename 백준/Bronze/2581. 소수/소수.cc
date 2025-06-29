#include <bits/stdc++.h>

using namespace std;

bool not_prime[10'001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  cin >> m >> n;

  int mnm = -1;
  int sum = 0;

  for (int i = 2; i <= n; ++i) {

    if (not_prime[i]) {
      continue;
    }

    for (int j = 2; i * j <= n; ++j) {
      not_prime[i * j] = true;
    }

    if (i < m) {
      continue;
    }

    sum += i;

    if (mnm < 0) {
      mnm = i;
    }
  }

  if (mnm < 0) {
    cout << -1;
  }
  else {
    cout << sum << '\n' << mnm;
  }
}