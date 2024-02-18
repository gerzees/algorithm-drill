#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, k;
int score[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0;i < n;++i)
    cin >> score[i];

  int cnt = 0;
  for (int i = n - 2;i >= 0;--i) {
    if (score[i] < score[i + 1]) continue;

    cnt += score[i] - (score[i + 1] - 1);
    score[i] = score[i + 1] - 1;
  }

  cout << cnt;
}