#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
/// <summary>
/// 트리의 각 노드
/// </summary>
struct node { int parent; int value; int left; int right; };
/// <summary>
/// 이진 검색 트리, bst[0] 루트
/// </summary>
node bst[10'001];
/// <summary>
/// 총 노드 개수
/// </summary>
int cnt_node;
/// <summary>
/// 후위 순위 결과
/// </summary>
vector<int> results;

void postorder(int cur_idx) {
  node& cur = bst[cur_idx];
  if (cur.left > 0) {
    postorder(cur.left);
  }
  if (cur.right > 0) {
    postorder(cur.right);
  }
  results.push_back(cur.value);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //*입력
  int num_input;
  // 루트 만들기
  cin >> num_input;
  bst[cnt_node++].value = num_input;
  // 나머지 노드 추가
  while (cin >> num_input) {
    // 추가될 노드 생성
    int cur_idx = cnt_node++;
    node& cur = bst[cur_idx];
    cur.value = num_input;
    int parent_idx = 0;

    // 추가될 노드 위치 찾기
    while (true) {
      node& parent = bst[parent_idx];

      if (cur.value < parent.value) {
        if (parent.left > 0) {
          parent_idx = parent.left;
          continue;
        }

        // 위치 찾음
        parent.left = cur_idx;
        cur.parent = parent_idx;
        break;
      }
      else {
        if (parent.right > 0) {
          parent_idx = parent.right;
          continue;
        }

        // 위치 찾음
        parent.right = cur_idx;
        cur.parent = parent_idx;
        break;
      }
    }
  }
  // 입력 끝*/

  //*처리
  postorder(0);
  // 처리 끝*/

  //*출력
  for (int result : results) {
    cout << result << '\n';
  }
  //출력 끝*/
}