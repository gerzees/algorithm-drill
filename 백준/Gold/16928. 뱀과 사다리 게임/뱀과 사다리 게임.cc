#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M;
/// <summary>
/// 사다림 or 뱀, 출발=인덱스, 도착-값
/// </summary>
int movement[101];
/// <summary>
/// 각 칸에 도달할 수 있는 최소 주사위 굴림 수
/// </summary>
int board[101];
/// <summary>
/// 다음 주사위 굴릴 위치
/// </summary>
queue<int> nextQ;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //*입력
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    movement[x] = y;
  }
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    movement[u] = v;
  }
  //입력 끝*/
  // 1에서 출발
  nextQ.push(1);
  // 100번 칸 도달할 때까지 반복
  while (board[100] == 0) {
    int cur = nextQ.front();
    nextQ.pop();

    for (int dx = 6; dx > 0; --dx) {
      int next = cur + dx;
      // 100번 칸 도달!
      if (next >= 100) {
        next = 100;
        board[next] = board[cur] + 1;
        break;
      }
      if (board[next] > 0) {
        // 이미 더 적은 굴림으로 도달함
        continue;
      }

      // cur에서 1번 굴려서 도달, cur에 도달하기 위한 굴림 수 + 1
      board[next] = board[cur] + 1;
      if (movement[next] == 0) {
        nextQ.push(next);
      }
      // next에 뱀이나 사다리가 있고 타고 이동한 곳에 더 적은 굴림으로 도달한 적이 없을 때
      else if (board[movement[next]] == 0) {
        // 타고 이동한 곳에 굴림 수 기록
        board[movement[next]] = board[next];
        nextQ.push(movement[next]);
      }
    }
  }

  //*출력
  cout << board[100];
  //출력 끝*/
}