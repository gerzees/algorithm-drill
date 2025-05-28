#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
/// <summary>
/// 집 크기
/// </summary>
int N;
/// <summary>
/// 집
/// </summary>
bool bWall[17][17];
/// <summary>
/// 방법의 수
/// </summary>
int result;

void push_pipe(int orient, int row, int col) {
  // 목적지 도달
  if (row == N && col == N) {
    ++result;
    return;
  }

  // 다음 위치로
  // 가로일 때
  if (orient == 0) {
    // 가로로
    if (bWall[row][col + 1] == false
      && col + 1 <= N) {
      push_pipe(0, row, col + 1);
    }
    // 대각으로
    if (bWall[row][col + 1] == false
      && bWall[row + 1][col] == false
      && bWall[row + 1][col + 1] == false
      && row + 1 <= N
      && col + 1 <= N) {
      push_pipe(1, row + 1, col + 1);
    }
  }
  // 대각일 때
  else if (orient == 1) {
    // 가로로
    if (bWall[row][col + 1] == false
      && col + 1 <= N) {
      push_pipe(0, row, col + 1);
    }
    // 대각으로
    if (bWall[row][col + 1] == false
      && bWall[row + 1][col] == false
      && bWall[row + 1][col + 1] == false
      && row + 1 <= N
      && col + 1 <= N) {
      push_pipe(1, row + 1, col + 1);
    }
    // 세로로
    if (bWall[row + 1][col] == false
      && row + 1 <= N) {
      push_pipe(2, row + 1, col);
    }
  }
  // 세로일 때
  else if (orient == 2) {
    // 대각으로
    if (bWall[row][col + 1] == false
      && bWall[row + 1][col] == false
      && bWall[row + 1][col + 1] == false
      && row + 1 <= N
      && col + 1 <= N) {
      push_pipe(1, row + 1, col + 1);
    }
    // 세로로
    if (bWall[row + 1][col] == false
      && row + 1 <= N) {
      push_pipe(2, row + 1, col);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //*입력
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cin >> bWall[i][j];
    }
  }
  // 입력 끝*/

  //*처리
  // 처음 파이프는 (1,1)(1,2)
  push_pipe(0, 1, 2);
  // 처리 끝*/

  //*출력
  cout << result;
  //출력 끝*/
}