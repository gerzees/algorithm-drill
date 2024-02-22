//09:42,10:06
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
string s, p;
int f[1'000'001];

void making_f(void) {
  f[0] = 0;
  int j = 0;
  for (int i = 1;i < p.size();++i) {
    while (j != 0 && p[i] != p[j]) {
      j = f[j - 1];
    }

    if (p[i] == p[j]) {
      f[i] = ++j;
    }
  }
}

bool is_p_in_s(void) {
  making_f();

  int j = 0;
  for (int i = 0;i < s.size();++i) {
    while (j != 0 && s[i] != p[j]) {
      j = f[j - 1];
    }
    if (s[i] == p[j]) {
      ++j;
    }

    if (j == p.size()) {
      return 1;
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> p;
  cout << (is_p_in_s() ? 1 : 0);
}