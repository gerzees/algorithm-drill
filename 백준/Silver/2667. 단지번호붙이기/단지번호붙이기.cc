//7:27, 8:00
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<vector<bool>> board(25, vector<bool>(25));
vector<vector<bool>> chk(25, vector<bool>(25));

int n;
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };

int get_count_house(const pair<int, int> st) {
  queue<pair<int, int>> q;
  q.push(st);
  int cnt_house = 1;
  chk[st.X][st.Y] = true;

  while (q.empty() == false) {
    auto [x, y] = q.front(); q.pop();

    for (int i = 0;i < 4;++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx == n || ny < 0 || ny == n) continue;

      if (board[nx][ny] == 0) continue;

      if (chk[nx][ny]) continue;

      q.push({ nx,ny });
      ++cnt_house;
      chk[nx][ny] = true;
    }
  }

  return cnt_house;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0;i < n;++i) {
    string line;
    cin >> line;
    vector<bool>::iterator board_iter = board[i].begin();

    for (char c : line) {
      *board_iter = c - '0';
      ++board_iter;
    }
  }

  vector<int> complex;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == 0) continue;

      if (chk[i][j]) continue;

      complex.push_back(get_count_house({ i, j }));
    }

  sort(complex.begin(), complex.end());

  cout << complex.size() << '\n';
  for (int each : complex) {
    cout << each << '\n';
  }
}