#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int M;

ull X = 1'000'000'007ull;
ull result;


int get_inverse(ull num, ull mod) {
  ull inverse = 1;
  ull exp = mod - 2;
  for (ull flag = 1; flag <= exp; flag <<= 1, num = (num * num) % mod) {
    if (!(flag & exp)) {
      continue;
    }

    inverse = (inverse * num) % mod;
  }

  return inverse;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> M;

  ull N, S;
  cin >> N >> S;

  for (int i = 0; i < M - 1; ++i) {
    ull Ni, Si;
    cin >> Ni >> Si;

    S = (S * Ni + Si * N) % X;
    N = (N * Ni) % X;
  }

  result = (S * get_inverse(N, X)) % X;

  cout << result;
}