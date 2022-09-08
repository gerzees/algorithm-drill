#include <bits/stdc++.h>

using namespace std;

inline void decode(void);
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  size_t count;
  cin >> count;
  for (size_t i = 0; i < count; i++) decode();
  return 0;
}

inline void decode(void) {
  string keylog;
  cin >> keylog;
  list<char> password;
  list<char>::const_iterator cursor = password.cend();
  for (const char& c : keylog) {
    switch (c) {
      case '-':
        if (cursor != password.cbegin() && !password.empty())
          cursor = password.erase(--cursor);
        break;
      case '<':
        if (cursor != password.cbegin()) --cursor;
        break;
      case '>':
        if (cursor != password.cend()) ++cursor;
        break;
      default:
        password.insert(cursor, c);
        break;
    }
  }
  for (const char& c : password) cout << c;
  cout << '\n';
}