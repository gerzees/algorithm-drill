// 9:41,9:57
#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> minHeap;
int N;
int num;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> num;
    minHeap.push(num);
  }

  for (int i = 0; i < N * (N - 1); ++i) {
    cin >> num;
    minHeap.push(num);
    minHeap.pop();
  }

  cout << minHeap.top();
}