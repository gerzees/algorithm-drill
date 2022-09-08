#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k, n;
  cin >> n >> k;
  list<int> cycle;
  string perm;  // Josephus permutation
  for (int i = 1; i <= n; i++) cycle.push_back(i);
  perm.append("<");
  list<int>::const_iterator it = cycle.cbegin();
  while (cycle.size() > 1) {
    for (int i = 0; i < k - 1; i++) {
      if (++it == cycle.cend()) it = cycle.cbegin();
    }
    perm.append(to_string(*it) + ", ");
    it = cycle.erase(it);
    if (it == cycle.cend()) it = cycle.cbegin();
  }
  perm.append(to_string(cycle.front()) + ">");
  cout << perm;
  return 0;
}