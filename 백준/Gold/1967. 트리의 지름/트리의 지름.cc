#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
/// <summary>
/// 노드 개수
/// </summary>
int n;
/// <summary>
/// 트리
/// </summary>
vector<pair<int, int>> edge[10'001];
/// <summary>
/// 트리의 지름
/// </summary>
int result;

int dnq(int root) {

  int longest = 0;
  int next_longest = 0;

  for (int i = 0; i < edge[root].size(); ++i) {
    int child = edge[root][i].X;
    int weight = edge[root][i].Y;
    int dist = dnq(child) + weight;

    if (dist > longest) {
      next_longest = longest;
      longest = dist;
    }
    else if (dist > next_longest) {
      next_longest = dist;
    }
  }

  // 트리의 지름 찾기
  result = max(result, longest + next_longest);

  return longest;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //*입력
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int parent, child, weight;
    cin >> parent >> child >> weight;
    edge[parent].push_back(pair<int, int>(child, weight));
  }

  // 입력 끝*/

  //*처리
  dnq(1);
  // 처리 끝*/

  //*출력
  cout << result;
  //출력 끝*/
}