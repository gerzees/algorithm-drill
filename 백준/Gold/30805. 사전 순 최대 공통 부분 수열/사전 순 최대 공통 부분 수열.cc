#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
int cnt_A;
int A[101];
int cnt_B;
int B[101];
vi cs[101][101];

// lh 부분 수열이 사전 순 뒤이면 양수 반환
// rh 부분 수열이 사전 순 뒤이면 음수 반환
// 같으면 0반환
int comp_cs(const vi& lh, const vi& rh) {
  if (lh.size() == 0 && rh.size() == 0) {
    return 0;
  }

  if (lh.size() > 0 && rh.size() == 0) {
    return 1;
  }
  if (lh.size() == 0 && rh.size() > 0) {
    return -1;
  }

  for (int i = 0; i < lh.size() && i < rh.size(); ++i) {
    if (lh[i] == rh[i]) {
      continue;
    }

    return lh[i] - rh[i];
  }

  return lh.size() - rh.size();
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


  for (int ia = 1; ia <= cnt_A; ++ia) {
    for (int ib = 1; ib <= cnt_B; ++ib) {
      cs[ia][ib] = cs[ia - 1][ib - 1];

      // 같은 경우
      if (A[ia] == B[ib]) {
        // cs[ia-1][ib-1]까지 확인 후 얻은 사전 순 가장 뒤 부분 수열과 A[ia]로
        // 사전 순 가장 뒤 부분 수열 만들기
        int i = 0;
        for (; i < cs[ia][ib].size(); ++i) {
          if (A[ia] > cs[ia][ib][i]) {
            break;
          }
        }

        cs[ia][ib].resize(i);
        cs[ia][ib].push_back(A[ia]);
      }


      if (comp_cs(cs[ia - 1][ib], cs[ia][ib - 1]) > 0) {
        if (comp_cs(cs[ia - 1][ib], cs[ia][ib]) > 0) {
          cs[ia][ib] = cs[ia - 1][ib];
        }
      }
      else {
        if (comp_cs(cs[ia][ib - 1], cs[ia][ib]) > 0) {
          cs[ia][ib] = cs[ia][ib - 1];
        }
      }
    }
  }

  vi& lcs = cs[cnt_A][cnt_B];
  cout << lcs.size();
  if (lcs.size() > 0) {
    cout << '\n';
    for (int num : lcs) {
      cout << num << ' ';
    }
  }
}