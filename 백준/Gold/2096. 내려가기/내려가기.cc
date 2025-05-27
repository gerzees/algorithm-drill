#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
/// <summary>
/// 줄 수
/// </summary>
int N;
/// <summary>
/// N개 줄의 숫자 저장
/// </summary>
char nums[100'000][3];
/// <summary>
/// 최대 저장
/// </summary>
int max_scores[2][3];
/// <summary>
/// 최소 저장
/// </summary>
int min_scores[2][3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //*입력
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      int num;
      cin >> num;
      nums[i][j] = num;
    }
  }
  // 입력 끝*/

  //*처리
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      max_scores[0][j] = max_scores[1][j];
      min_scores[0][j] = min_scores[1][j];
    }

    // 좌
    int max_score_left = max(max_scores[0][0], max_scores[0][1]);
    int min_score_left = min(min_scores[0][0], min_scores[0][1]);
    max_scores[1][0] = nums[i][0] + max_score_left;
    min_scores[1][0] = nums[i][0] + min_score_left;

    // 우
    int max_score_right = max(max_scores[0][2], max_scores[0][1]);
    int min_score_right = min(min_scores[0][2], min_scores[0][1]);
    max_scores[1][2] = nums[i][2] + max_score_right;
    min_scores[1][2] = nums[i][2] + min_score_right;

    // 중
    max_scores[1][1] = nums[i][1] + max(max_score_left, max_score_right);
    min_scores[1][1] = nums[i][1] + min(min_score_left, min_score_right);
  }
  // 처리 끝*/

  //*출력
  cout << max(max(max_scores[1][0], max_scores[1][1]), max_scores[1][2]) << ' ' << min(min(min_scores[1][0], min_scores[1][1]), min_scores[1][2]);
  //출력 끝*/
}