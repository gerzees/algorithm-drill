#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
int cnt_A;
int A[101];
int cnt_B;
int B[101];

void get_lcs(int ia_start, int ib_start, vi& lcs) {
  // 주어진 범위 내에서 가장 큰 공통 부분 수열 원소 찾기
  int big_ia = 0;
  int big_ib = 0;
  for (int ia = ia_start; ia <= cnt_A; ++ia) {
    for (int ib = ib_start; ib <= cnt_B; ++ib) {
      if (A[ia] != B[ib]) {
        continue;
      }

      // 같을 때 더 큰 수 찾으면 갱신
      if (big_ia == 0 || A[big_ia] < A[ia]) {
        big_ia = ia;
        big_ib = ib;
      }
    }
  }

  // 공통 부분 수열 원소 못찾으면 끝
  if (big_ia == 0) {
    return;
  }

  // 찾으면 
  // 가장 큰 원소 공통 부분 수열에 추가하고
  lcs.push_back(A[big_ia]);
  // 남은 범위에서 다시 가장 큰 공통 부분 수열 원소 찾기
  get_lcs(big_ia + 1, big_ib + 1, lcs);
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> cnt_A;
  for (int i = 1; i <= cnt_A; ++i) {
    cin >> A[i];
  }

  cin >> cnt_B;
  for (int i = 1; i <= cnt_B; ++i) {
    cin >> B[i];
  }
  vi lcs;
  lcs.reserve(100);
  get_lcs(1, 1, lcs);

  cout << lcs.size();
  if (lcs.size() > 0) {
    cout << '\n';
    for (int num : lcs) {
      cout << num << ' ';
    }
  }
}