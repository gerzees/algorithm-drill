#include <bits/stdc++.h>
using namespace std;
int M;
unsigned long long p = 1'000'000'007ull;
unsigned long long result;

int get_gcd(unsigned long long a, unsigned long long b) {
  unsigned long long r = a % b;

  if (r == 0) {
    return b;
  }

  return get_gcd(b, r);
}

int get_inverse(unsigned long long num, unsigned long long mod) {
  unsigned long long inverse = 1;
  unsigned long long exp = mod - 2;
  for (unsigned long long flag = 1; flag <= exp; flag <<= 1, num = (num * num) % mod) {
    if (!(flag & exp)) {
      continue;
    }

    inverse *= num;
    inverse %= mod;
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
    unsigned long long gcd = get_gcd(S, N);
    N /= gcd;
    S /= gcd;

    if (S % N == 0) {
      result += S / N;
      continue;
    }

    result += S * get_inverse(N, p);
    result %= p;
  }

  cout << result;
}