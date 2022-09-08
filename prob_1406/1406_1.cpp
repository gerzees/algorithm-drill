#include <bits/stdc++.h>

using namespace std;
constexpr size_t MX = 600001;
// pre[0]== addr of the last element
int pre[MX];
char dat[MX];
// nxt[0]== addr of the first element
int nxt[MX];
int unused = 1;
int insert(const int addr, const char c) {
  pre[unused] = addr;
  dat[unused] = c;
  nxt[unused] = nxt[addr];
  if (nxt[addr] != -1)
    pre[nxt[addr]] = unused;
  else
    pre[0] = unused;
  nxt[addr] = unused;
  return unused++;
}
int erase(const int addr) {
  nxt[pre[addr]] = nxt[addr];
  if (nxt[addr] != -1)
    pre[nxt[addr]] = pre[addr];
  else
    pre[0] = pre[addr];
  return pre[addr];
}
void push_back(const char c) {
  if (pre[0] != -1)  // unused!=1, list is not empty
    insert(pre[0], c);
  else
    insert(0, c);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);
  //   fill(dat, dat + MX, (char)-1);
  string initTxt;
  getline(cin, initTxt);
  for (const char& c : initTxt) push_back(c);
  int cursor = pre[0];
  int count;
  cin >> count;
  for (int i = 0; i < count; i++) {
    char command;
    cin >> command;
    switch (command) {
      case 'L':
        if (cursor != 0) cursor = pre[cursor];
        break;
      case 'D':
        if (cursor != pre[0]) cursor = nxt[cursor];
        break;
      case 'P': {
        char c;
        cin >> c;
        // if (cursor != 0) cursor = pre[cursor];
        cursor = insert(cursor, c);
      } break;
      case 'B':
        if (cursor != 0) cursor = erase(cursor);
        break;
      default:
        break;
    }
  }
  for (int iter = nxt[0]; iter != -1; iter = nxt[iter]) cout << dat[iter];
  return 0;
}