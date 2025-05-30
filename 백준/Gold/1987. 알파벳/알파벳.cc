#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
/// <summary>
/// 세로 칸 수
/// </summary>
int R;
/// <summary>
/// 가로 칸 수
/// </summary>
int C;
/// <summary>
/// 대문자 알파벳으로 구성된 표 모양 보드
/// </summary>
string table[21];
/// <summary>
/// 알파벳 지났는지 체크
/// </summary>
bool bPassed[30];
/// <summary>
/// 지날 수 있는 최대 칸 수
/// </summary>
int result;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

void dfs(int r, int c, int dist) {
  if (dist > result) {
    // 최대 칸 수 갱신 
    result = dist;
  }

  // 사방으로 확인 후 전진
  for (int i = 0; i < 4; ++i) {
    int next_r = r + dr[i];
    int next_c = c + dc[i];

    // 표 벗어나는 지 검사
    if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) {
      continue;
    }

    int idx = table[next_r][next_c] - 'A';
    // 이미 지나온 알파벳으로 전진 불가
    if (bPassed[idx]) {
      continue;
    }

    // 전진
    bPassed[idx] = true;
    dfs(next_r, next_c, dist + 1);
    // 전진 끝 원상 복구
    bPassed[idx] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //*입력
  cin >> R >> C;
  for (int r = 0; r < R; ++r) {
    cin >> table[r];
  }
  // 입력 끝*/

  //*처리
  // 시작 점 체크
  int idx = table[0][0] - 'A';
  bPassed[idx] = true;
  dfs(0, 0, 1);
  // 처리 끝*/

  //*출력
  cout << result;
  //출력 끝*/
}