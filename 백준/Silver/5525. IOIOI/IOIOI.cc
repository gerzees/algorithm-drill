#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M;
string S;
int cnt_P_N;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //*입력
  cin >> N >> M >> S;
  //입력 끝*/

  for (int i = 0, j; i < M; ++i) {
    if (S[i] != 'I') {
      continue;
    }
    
    // 'I' 시작
    j = i;
    while (j + 2 < M && S[j + 1] == 'O' && S[j + 2] == 'I') {
      j += 2;
    }
    
    int cnt_O = (j - i) / 2;
    if (cnt_O >= N) {
      cnt_P_N += cnt_O - N + 1;
    }
   
    // 확인한 부분 다시 확인하지 않도록 포인터 이동
    i = j;
  }

  //*출력
  cout << cnt_P_N;
  //출력 끝*/
}