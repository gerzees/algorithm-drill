#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
/// <summary>
/// 도시의 개수
/// </summary>
int N;
/// <summary>
/// 버스의 개수
/// </summary>
int M;
/// <summary>
/// 그래프 저장, 인덱스= 출발 도시, 벡터의 요소=도착 도시와 가격 
/// </summary>
vector<pair<int, int>> edges[1'001];
/// <summary>
/// 구하는 구간의 시작도시
/// </summary>
int u;
/// <summary>
/// 구하는 구간의 도착도시
/// </summary>
int v;
/// <summary>
/// 탐색 시 다음 출발 도시 꺼내기, 비용과 도시
/// </summary>
priority_queue < 
  pair<int, int>, 
  vector < pair<int, int>>,
  greater<pair<int, int>>
> next_cities;
/// <summary>
/// 탐색 여부 확인
/// </summary>
bool bVisits[1'001];
/// <summary>
/// 구간의 비용
/// </summary>
int result;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //*입력
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int src, dst, fee;
    cin >> src >> dst >> fee;
    edges[src].push_back(pair<int, int>(dst, fee));
  }
  cin >> u >> v;
  // 입력 끝*/

 //*처리
  next_cities.push(pair<int, int>(0, u));
  while (true) {
    pair<int, int>cur = next_cities.top();
    next_cities.pop();
    int city = cur.Y;
    int cost = cur.X;

    if (bVisits[city]) {
      // 탐색 끝난 건 제외
      continue;
    }

    if (city == v) {
      result = cost;
      break;
    }

    bVisits[city] = true;

    for (pair<int, int> bus : edges[city]) {
      int dst = bus.X;
      int fee = bus.Y;

      if (bVisits[dst]) {
        // 탐색 끝난 건 제외
        continue;
      }

      next_cities.push(pair<int, int>(cost + fee, dst));
    }
  }
  // 처리 끝*/

  //*출력
  cout << result;
  //출력 끝*/
}