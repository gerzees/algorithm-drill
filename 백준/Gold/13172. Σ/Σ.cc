#include <bits/stdc++.h>
using namespace std;
int M;
unsigned long long p = 1'000'000'007ull;
unsigned long long result;

int get_inverse(unsigned long long num, unsigned long long mod) {
  unsigned long long inverse = 1;
  unsigned long long exp = mod - 2;
  for (unsigned long long flag = 1; flag <= exp; flag <<= 1, num = (num * num) % mod) {
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

  for (int i = 0; i < M; ++i) {
    unsigned long long N, S;
    cin >> N >> S;
    result += (S * get_inverse(N, p))%p;
  }
  result %= p;

  cout << result;
}