#include<bits/stdc++.h>

using namespace std;

string NO_CHAR = "FRULA";
string str;
string bomb;
/// <summary>
/// result의 인덱스
/// </summary>
int ri;
char result[1'000'001];
/// <summary>
/// idxs의 인덱스
/// </summary>
int ii;
char idxs[1'000'001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //입력
  str.reserve(1'000'000);
  bomb.reserve(36);
  cin >> str >> bomb;

  // 처리
  int bomb_idx = 0;
  for (char c : str) {
    if (c != bomb[bomb_idx]) {
      // 폭발문자열 첫 문자와 비교라면 더 볼 것도 없음
      if (bomb_idx == 0) {
        result[ri++] = c;
        idxs[ii++] = bomb_idx;
        continue;
      }

      // 폭발문자열 2번째 문자부터는 다르면 첫 문자와 비교도 필요함
      bomb_idx = 0;

      if (c != bomb[bomb_idx]) {
        result[ri++] = c;
        idxs[ii++] = bomb_idx;
        continue;
      }
    }

    ++bomb_idx;

    if (bomb_idx == bomb.length()) {
      // 폭발문자열 폭발!
      for (int i = 0; i < bomb_idx - 1; ++i) {
        --ii;
        --ri;
      }

      bomb_idx = ii == 0 ? 0 : idxs[ii - 1];
      continue;
    }

    // 폭발 문자열과 중복인 부분 발견 > 추적
    result[ri++] = c;
    idxs[ii++] = bomb_idx;
  }

  // 출력
  if (ri == 0) {
    cout << NO_CHAR;

    return 0;
  }

  result[ri] = '\0';
  cout << result;
}