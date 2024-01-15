// 10:30, 10,:47
#include<bits/stdc++.h>
using namespace std;

int N, x;
priority_queue<int> mxHeap;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  while (N--) {
    cin >> x;
    
    if (x != 0) { // 배열에 자연수 넣기
      mxHeap.push(x);
      continue;
    }

    //배열의 최대 출력, 제거
    if (mxHeap.empty()) {
      cout << 0 << '\n';
      continue;
    }

    cout << mxHeap.top() << '\n';
    mxHeap.pop();
  }
}