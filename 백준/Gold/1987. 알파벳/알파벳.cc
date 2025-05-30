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
/// 해당 칸에 도달할 때 지나온 알파벳 조합 bit로 저장
/// </summary>
set<int> prev_alphas[21][21];
/// <summary>
/// 지날 수 있는 최대 칸 수
/// </summary>
int result;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

void dfs(int r, int c, int cnt_alphas, int alphas) {
  if (cnt_alphas > result) {
    // 최대 칸 수 갱신 
    result = cnt_alphas;
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
    int next_alphas = alphas | 1 << idx;
    // 이미 지나온 알파벳으로 전진 불가
    if (next_alphas == alphas) {
      continue;
    }

    pair<set<int>::iterator, bool> insert_result = prev_alphas[next_r][next_c].insert(next_alphas);
    // 이전에 같은 알파벳 조합으로 도달한 적 있음
    if (insert_result.Y == false) {
      continue;
    }

    dfs(next_r, next_c, cnt_alphas + 1, next_alphas);
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
  int alphas = 1 << idx;
  prev_alphas[0][0].insert(alphas);
  dfs(0, 0, 1, alphas);
  // 처리 끝*/

  //*출력
  cout << result;
  //출력 끝*/
}