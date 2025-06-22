#include <bits/stdc++.h>

using namespace std;
// first idx, second heights
stack<pair<int, int>> left_top;
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    cin >> n;

    if (n == 0) {
      break;
    }

    long long mxm = 0;

    for (int i = 0; i < n; ++i) {
      int left = i;
      int height;
      cin >> height;

      while (left_top.empty() == false && left_top.top().second > height) {
        mxm = max(mxm, (i - left_top.top().first) * (long long)left_top.top().second);
        left = left_top.top().first;
        left_top.pop();
      }

      if (left_top.empty() == false && left_top.top().second == height) {
        continue;
      }

      left_top.push({ left, height });
    }

    while (left_top.empty() == false) {
      mxm = max(mxm, (n - left_top.top().first) * (long long)left_top.top().second);
      left_top.pop();
    }

    cout << mxm << '\n';
  }
}