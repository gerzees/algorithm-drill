#include <bits/stdc++.h>

using namespace std;

constexpr size_t MX = 1000001;
int pre[MX];
int nxt[MX];
char dat[MX];
int unused = 1;
inline void erase(int addr) {
  nxt[pre[addr]] = nxt[addr];
  if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}
inline void insert(int addr, int c) {
  pre[unused] = addr;
  dat[unused] = c;
  nxt[unused] = nxt[addr];
  if (nxt[addr] != -1) pre[nxt[addr]] = unused;
  nxt[addr] = unused;
  ++unused;
}
inline void traverse() {
  for (int cur = nxt[0]; cur != -1; cur = nxt[cur]) cout << dat[cur];
  cout << '\n';
}
inline void resetList() {
  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);
  unused = 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  size_t count;
  cin >> count;
  for (size_t i = 0; i < count; i++) {
    int cursor = 0;
    string keylog;
    resetList();
    cin >> keylog;
    for (const char &c : keylog) {
      switch (c) {
        case '-':
          if (cursor != 0) {
            erase(cursor);
            cursor = pre[cursor];
          }
          break;
        case '<':
          if (cursor != 0) cursor = pre[cursor];
          break;
        case '>':
          if (nxt[cursor] != -1) cursor = nxt[cursor];
          break;
        default:
          insert(cursor, c);
          cursor = nxt[cursor];
          break;
      }
    }
    traverse();
  }
  return 0;
}