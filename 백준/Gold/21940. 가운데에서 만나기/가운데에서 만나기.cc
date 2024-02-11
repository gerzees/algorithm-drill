#include <bits/stdc++.h>

using namespace std;

int city[201];
int d[201][201];
const int INF = 0x3f3f3f3f;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  
  for (size_t i = 1; i <= n; i++)
  {
    fill(d[i], d[i] + 1 + n, INF);
    d[i][i] = 0;
  }

  for (size_t i = 0; i < m; i++)
  {
    int a, b, t;
    cin >> a >> b >> t;
    d[a][b] = t;
  }
  
  int k;
  cin >> k;
  
  for (size_t i = 0; i < k; i++)
  {
    cin >> city[i];
  }

  for (size_t mid = 1; mid <= n; mid++)
  {
    for (size_t i = 1; i <= n; i++)
    {
      for (size_t j = 1; j <= n; j++)
      {
        if (d[i][mid] + d[mid][j] < d[i][j])
        {
          d[i][j] = d[i][mid] + d[mid][j];
        }
      }
    }
  }

  int x_dist;
  vector<int> ans;
  
  for (size_t i = 1; i <= n; i++)
  {
    int max_dist = 0;
    for (size_t j = 0; j < k; j++)
    {
      if (d[i][city[j]] == INF || d[city[j]][i] == INF)
      {
        max_dist = -1;
        break;
      }

      if (max_dist < d[i][city[j]] + d[city[j]][i])
      {
        max_dist = d[i][city[j]] + d[city[j]][i];
      }
    }
    
    if(max_dist == -1)
    {
      continue;
    }
    
    if (ans.size() == 0)
    {
      x_dist = max_dist;
      ans.push_back(i);
    }
    else if (x_dist == max_dist)
    {
      ans.push_back(i);
    }
    else if (x_dist > max_dist)
    {
      x_dist = max_dist;
      ans.clear();
      ans.push_back(i);
    }
  }

  for (int x : ans)
  {
    cout << x << ' ';
  }
}