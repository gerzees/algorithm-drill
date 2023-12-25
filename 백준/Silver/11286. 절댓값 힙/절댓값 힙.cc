// 9:30,9:55
#include<bits/stdc++.h>
using namespace std;

template<class T>
struct absGreater {
  constexpr bool operator()(const T& lhs, const T& rhs) const {
    T absL = lhs;
    if (absL < 0) absL = -lhs;

    T absR = rhs;
    if (absR < 0) absR = -rhs;

    if (absL == absR) {
      return lhs > rhs;
    }

    return absL > absR;
  }
};

priority_queue<int, vector<int>, absGreater<int>> PQ;
int N, x;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while (N--) {
    cin >> x;

    if (x == 0) {
      if (PQ.empty()) {
        cout << 0 << '\n';
        continue;
      }

      cout << PQ.top() << '\n';
      PQ.pop();
      continue;
    }

    PQ.push(x);
  }
}