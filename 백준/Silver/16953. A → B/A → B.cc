#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
/// <summary>
/// 입력, A<B
/// </summary>
int A, B;
/// <summary>
/// A를 B로 바꾸는데 필요한 연산의 최솟값에 1을 더한 값, 만들 수 없으면 -1
/// </summary>
int result;

void next_step(long long cur, int depth) {
  if (cur == B) {
    if (depth + 1 < result || result == 0) {
      result = depth + 1;
    }
    return;
  }

  if (cur > B) {
    return;
  }

  next_step(cur * 2, depth + 1);
  next_step(cur * 10 + 1, depth + 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //*입력
  cin >> A >> B;
  // 입력 끝*/

  next_step(A, 0);

  //*출력
  if (result == 0) {
    cout << -1;
  }
  else {
    cout << result;
  }
  //출력 끝*/
}