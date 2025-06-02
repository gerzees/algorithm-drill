#include<bits/stdc++.h>

using namespace std;

string NO_CHAR = "FRULA";
string str;
string bomb;
vector<char> result;
vector<char> idxs;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //입력
  str.reserve(1'000'000);
  bomb.reserve(36);
  result.reserve(1'000'000);
  idxs.reserve(1'000'000);

  cin >> str >> bomb;

  // 처리
  int bomb_idx = 0;
  for (char c : str) {
    if (c != bomb[bomb_idx]) {
      // 폭발문자열 첫 문자와 비교라면 더 볼 것도 없음
      if (bomb_idx == 0) {
        result.push_back(c);
        idxs.push_back(bomb_idx);
        continue;
      }

      // 폭발문자열 2번째 문자부터는 다르면 첫 문자와 비교도 필요함
      bomb_idx = 0;

      if (c != bomb[bomb_idx]) {
        result.push_back(c);
        idxs.push_back(bomb_idx);
        continue;
      }
    }

    ++bomb_idx;

    if (bomb_idx == bomb.length()) {
      // 폭발문자열 폭발!
      for (int i = 0; i < bomb_idx - 1; ++i) {
        idxs.pop_back();
        result.pop_back();
      }

      bomb_idx = idxs.empty() ? 0 : idxs.back();

      continue;
    }

    // 폭발 문자열과 중복인 부분 발견 > 추적
    idxs.push_back(bomb_idx);
    result.push_back(c);
  }

  // 출력
  if (result.size() == 0) {
    cout << NO_CHAR;

    return 0;
  }

  string result_str(result.begin(), result.end());
  cout << result_str;
}