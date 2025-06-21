#include <bits/stdc++.h>
using namespace std;

int a[1'000'001];
int n;

stack<int> bigger;
stack<int> result;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = n - 1; i >= 0; --i) {

    while (bigger.empty() == false && a[i] >= bigger.top()) {
      bigger.pop();
    }

    if (bigger.empty()) {
      result.push(-1);
    }
    else {
      result.push(bigger.top());
    }

    bigger.push(a[i]);
  }

  while (result.empty() == false) {
    cout << result.top() << ' ';
    result.pop();
  }
}