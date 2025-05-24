#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
/// <summary>
/// 테스트 케이스 개수
/// </summary>
int T;
/// <summary>
/// 열의 수
/// </summary>
int n;
/// <summary>
/// 각 테스트 케이스마다 입력 스티커 점수 저장
/// </summary>
int values[2][100'000];
/// <summary>
/// 각 열에서 선택지(선택 x, 1행 선택, 2행 선택)를 골랐을 때의 최댓값
/// </summary>
int max_val[3][100'000];
/// <summary>
/// 각 테스트 케이스의 최댓값 저장
/// </summary>
vector<int> results;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //*입력
  cin >> T;
  results.reserve(T);
  // 입력 끝*/

 //*처리
  for (int i = 0; i < T; ++i) {
    fill(max_val[0], max_val[0] + sizeof(max_val) / sizeof(int), 0);

    cin >> n;

    for (int row = 0; row < 2; ++row) {
      for (int col = 0; col < n; ++col) {
        cin >> values[row][col];
      }
    }
    // 0 열
    // 0 행 선택
    max_val[0][0] = values[0][0];
    // 1 행 선택
    max_val[1][0] = values[1][0];

    for (int col = 1; col < n; ++col) {
      // 0 행 선택: 이전 col에서 1행 선택했을 경우와 선택하지 않은 경우의 최댓값 비교
      max_val[0][col] = max(max_val[1][col - 1], max_val[2][col - 1]) + values[0][col];
      // 1 행 선택
      max_val[1][col] = max(max_val[0][col - 1], max_val[2][col - 1]) + values[1][col];
      // 어느 행도 선택 x
      max_val[2][col] = max(max_val[0][col - 1], max_val[1][col - 1]);
    }

    // 마지막 행의 최댓값 선택지 3개 중 가장 큰 값이 최댓값
    results.push_back(max(max(max_val[0][n - 1], max_val[1][n - 1]), max_val[2][n - 1]));
  }
  // 처리 끝*/

  //*출력
  for (int result : results) {
    cout << result << '\n';
  }
  //출력 끝*/
}