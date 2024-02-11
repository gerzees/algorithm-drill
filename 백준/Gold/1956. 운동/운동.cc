// 00:23,12:57
#include <bits/stdc++.h>
/*
방향 그래프
최소 거리 사이클(두 마을 왕복 경우 포함)
  두 마을 왕복 중 최소 거리
  플로이드 돌리면 각 두 마을 편도 최소 거리 알 수 있다(사이에 뭘 거치든)
  a->b b->a: a와 b가 포함되 사이클 중 최단 거리
    모든 쌍 비교해서 최소 찾으면 될 듯.
*/
using namespace std;

int d[401][401];
const int INF = 0x3f3f3f3f;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int v, e;
  cin >> v >> e;

  for (int i = 1; i <= v; ++i)
  {
    fill(d[i], d[i] + v + 1, INF);
    d[i][i] = 0;
  }

  while (e--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    d[a][b] = c;
  }

  for (size_t k = 1; k <= v; ++k)
    for (size_t i = 1; i <= v; ++i)
      for (size_t j = 1; j <= v; ++j)
        if (d[i][k] + d[k][j] < d[i][j])
        {
          d[i][j] = d[i][k] + d[k][j];
        }

  int ans = INF;
  for (size_t i = 1; i < v; ++i)
    for (size_t j = i + 1; j <= v; ++j)
      if (d[i][j] + d[j][i] < ans)
      {
        ans = d[i][j] + d[j][i];
      }

  cout << (ans == INF ? -1 : ans);
}