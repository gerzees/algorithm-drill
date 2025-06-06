#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int cnt;

ull M = 1'000'000'007ull;
ull result;


int get_inverse(int a) {
  int y = 0;
  int x = 1;
  int m = M;
  while (a > 1) {
    int q = a / m;
    int t = m;

    m = a % m;
    a = t;
    t = y;

    y = x - q * y;
    x = t;
  }
  if (x < 0)
    x += M;

  return x;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> cnt;

  ull N, S;
  cin >> N >> S;

  for (int i = 0; i < cnt - 1; ++i) {
    ull Ni, Si;
    cin >> Ni >> Si;

    S = (S * Ni + Si * N) % M;
    N = (N * Ni) % M;
  }

  result = (S * get_inverse(N)) % M;

  cout << result;
}