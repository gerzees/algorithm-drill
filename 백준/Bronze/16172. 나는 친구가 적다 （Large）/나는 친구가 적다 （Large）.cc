//10:29,10:49
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
string s, k;
int f[200'001];

bool is_keyword() {
  //실패함수 만들고
  int j = 0;
  f[0] = 0;
  for (int i = 1;i < k.size();++i) {
    // j번째 불일치, 길이 j-1 문자열에서 접두사 접미사 겹치는 길이(다음에 확인할 인덱스)
    while (j > 0 && k[i] != k[j]) j = f[j - 1];

    if (k[i] == k[j])f[i] = ++j;
  }

  //KMP(k가 s에 있는지 검사)
  j = 0;
  for (int i = 0;i < s.size();++i) {
    if (isdigit(s[i])) continue; // 숫자 버린다

    while (j > 0 && s[i] != k[j]) j = f[j - 1];

    if (s[i] == k[j]) ++j;

    if (j == k.size())
      return true;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> k;
  cout << is_keyword();
}