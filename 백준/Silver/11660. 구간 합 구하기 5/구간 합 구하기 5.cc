#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
/// <summary>
/// 표의 크기
/// </summary>
int N;
/// <summary>
/// 합 구할 횟수
/// </summary>
int M;
/// <summary>
/// 표 저장할 배열(2차원): 표를 그대로 저장하는 것이 아닌, (1,1)부터 (x,y)까지 합을 저장
/// </summary>
int table[1'025][1'025];
/// <summary>
/// 각 합을 저장
/// </summary>
vector<int> results;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //*입력
  cin >> N >> M;
  for (int x = 1; x <= N; ++x) {
    for (int y = 1; y <= N; ++y) {
      cin >> table[x][y];
      // (1,1)부터 (x,y)까지 합을 table[x][y]에 저장
      table[x][y] = table[x][y] + table[x - 1][y] + table[x][y - 1] - table[x - 1][y - 1];
    }
  }
  // 입력 끝*/

 //*처리
  for (int i = 0; i < M; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    results.push_back(table[x2][y2] - table[x2][y1 - 1] - table[x1 - 1][y2] + table[x1 - 1][y1 - 1]);
  }

  // 처리 끝*/

  //*출력
  for (int result : results) {
    cout << result << '\n';
  }
  //출력 끝*/
}