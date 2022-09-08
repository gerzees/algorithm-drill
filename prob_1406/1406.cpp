#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string initTxt;
  list<char> txt;
  size_t count;
  getline(cin, initTxt);
  for (const char& c : initTxt) txt.push_back(c);
  list<char>::const_iterator cursor = txt.cend();
  cin >> count;
  for (size_t i = 0; i < count; i++) {
    char command;
    cin >> command;
    switch (command) {
      case 'P': {
        char c;
        cin >> c;
        // cursor = txt.insert(cursor, c);
        txt.insert(cursor, c);
      } break;
      case 'L':
        if (cursor != txt.cbegin()) --cursor;
        break;
      case 'D':
        if (cursor != txt.cend()) ++cursor;
        break;
      case 'B':
        if (cursor != txt.cbegin()) {
          --cursor;
          cursor = txt.erase(cursor);
        }
        break;
      default:
        break;
    }
  }
  for (const char& c : txt) cout << c;
  return 0;
}