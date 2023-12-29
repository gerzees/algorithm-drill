// 8:34, 8:54
#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> problemsByDeadline[200'001];
priority_queue<int> pq;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0;i < N;++i) {
    int deadline, ramenCnt;
    cin >> deadline >> ramenCnt;

    problemsByDeadline[deadline].push_back(ramenCnt);
  }

  int cnt = 0;

  for (int t = N; t > 0; --t) {

    for (int ramen : problemsByDeadline[t])
      pq.push(ramen);

    if (pq.empty()) continue;

    cnt += pq.top();
    pq.pop();
  }

  cout << cnt;
}