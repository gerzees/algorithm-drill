#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
/// <summary>
/// 트리의 각 노드
/// </summary>
struct node { int value; int left; int right; };
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

//다음 원소 받는 것과 순회하는 것 분리
// 다음 원소 받아, 현재 원소와 비교
// 작다 왼쪽으로, 크다 상위로 올라감
// 왼쪽으로 갈 때만 재귀로 아닐 때는 반복문으로 처리

int preorder(int parent_idx) {
  int new_node_value;

  while (cin >> new_node_value) {
    int cur_node_idx = cnt_node;
    int new_node_idx = ++cnt_node;
    bst[new_node_idx].value = new_node_value;

    if (bst[cur_node_idx].value > bst[new_node_idx].value) {
      bst[cur_node_idx].left = new_node_idx;
      // 왼쪽으로 가지 치기
      new_node_idx = preorder(cur_node_idx);
      // 추가 노드 없음
      if (new_node_idx == 0) {
        return 0;
      }
    }

    // 비교할 더 큰 조상 없거나
    // 새 값이 그 조상보다 작으면
    if (parent_idx < 0
      || bst[new_node_idx].value < bst[parent_idx].value
      ) {
      // 오른쪽에 붙이면 됨
      bst[cur_node_idx].right = new_node_idx;
      // 현재 노드는 오른쪽에 붙인 노드로 갱신
      cur_node_idx = new_node_idx;

      continue;
    }

    // 오른쪽에 못 붙이면 조상에게 맡겨야 함
    return new_node_idx;
  }

  // 추가 원소 없음 종료
  return 0;
}



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
  cin >> bst[0].value;
  preorder(-1);
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