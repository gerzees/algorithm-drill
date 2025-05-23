#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

/// <summary>
/// 테스트 케이스 수
/// </summary>
int T;
/// <summary>
/// 레지스터 초기 값
/// </summary>
int A;
/// <summary>
/// 레지스터 최종 값
/// </summary>
int B;
/// <summary>
/// A에서 인덱스로 변환하는 최소한의 명령어 나열로 변환 과정에서 마지막 명령어 
/// </summary>
char op[10'001];
/// <summary>
/// A에서 인덱스로 변환하는 명령어 나열 길이
/// </summary>
int op_arr_len[10'001];
/// <summary>
/// A에서 인덱스로 변환 과정에서 인덱스 직전 정수
/// </summary>
int prev_num[10'001];

auto D_op = [](int cur)->int {
  int next = cur * 2;
  return next % 10'000;
  };
auto S_op = [](int cur)->int {
  if (cur == 0) {
    return 9'999;
  }
  return cur - 1;
  };
auto L_op = [](int cur)->int {
  int next = cur * 10;
  next += cur / 1'000;
  return next % 10'000;
  };
int (*R_op)(int) = [](int cur)->int {
  int next = cur * 1'000;
  next += cur / 10;
  return next % 10'000;
  };

int (*ops[])(int) = { D_op,S_op,L_op,R_op };
char op_char[] = "DSLR";
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // */
  //*입력
  cin >> T;

  vector<string> results(T);

  for (int t = 0; t < T; ++t) {
    cin >> A >> B;
    memset(op, 0, sizeof(op));
    memset(op_arr_len, 0, sizeof(op_arr_len));

    queue<int> Q;
    Q.push(A);
    while (true) {
      int cur = Q.front();
      Q.pop();

      if (cur == B) {
        break;
      }

      for (int i = 0; i < 4; ++i) {
        int next = ops[i](cur);

        if (next == A) {
          continue;
        }
        if (op_arr_len[next] > 0
          && op_arr_len[next] <= op_arr_len[cur] + 1) {
          continue;
        }

        op[next] = op_char[i];
        op_arr_len[next] = op_arr_len[cur] + 1;
        prev_num[next] = cur;
        Q.push(next);
      }
    }

    string op_arr;
    {
      int cur = B;
      while (cur != A) {
        op_arr += op[cur];
        cur = prev_num[cur];
      }
    }
    reverse(op_arr.begin(), op_arr.end());
    results.push_back(op_arr);
  }

  //*출력
  for (string s : results) {
    cout << s << '\n';
  }
  //출력 끝*/
}