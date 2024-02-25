#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int LENGTH = 1'000'001;
char t[LENGTH];
char p[LENGTH];
int f[LENGTH];
vector<int> pos;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin.getline(t, LENGTH);
  cin.getline(p, LENGTH);

  int j = 0;

  for (int i = 1;p[i] != '\0';++i) {
    while (j > 0 && p[i] != p[j]) j = f[j - 1];

    if (p[i] == p[j]) f[i] = ++j;
  }

  j = 0;

  for (int i = 0;t[i] != '\0';++i) {
    while (j > 0 && t[i] != p[j]) j = f[j - 1];

    if (t[i] == p[j]) ++j;

    if (p[j] == '\0') {
      pos.push_back(i - j + 2);
      j = f[j - 1];
    }
  }

  cout << pos.size() << '\n';
  for (int i : pos) {
    cout << i << ' ';
  }
}