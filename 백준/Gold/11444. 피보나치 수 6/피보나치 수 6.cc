#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
int mod = 1'000'000'007;
unordered_map<ll, ll> memo;

ll get_fibo(ll n) {
  if (n == 0) {
    return 0;
  }
  if (n < 3) {
    return 1;
  }

  // 기존에 구한 거 있음
  if (memo.find(n) != memo.end()) {
    return memo[n];
  }

  // 기존에 계산한 거 없으면 계산
  ll k = n / 2;
  ll result;

  // 홀수
  if (n % 2 == 1) {
    result = get_fibo(k + 1) * get_fibo(k + 1) % mod;
    result += get_fibo(k) * get_fibo(k) % mod;
  }
  // 짝수
  else {
    result = get_fibo(k + 1) * get_fibo(k) % mod;
    result += get_fibo(k) * get_fibo(k - 1) % mod;
  }

  result %= mod;
  memo[n] = result;

  return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  cout << get_fibo(n);
}