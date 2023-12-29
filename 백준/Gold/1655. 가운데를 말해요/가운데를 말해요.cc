// 8:51, 9:47
#include<bits/stdc++.h>
using namespace std;

priority_queue<int> smallHalf;
priority_queue<int, vector<int>, greater<>> bigHalf;
int N, num;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N;++i) {
    cin >> num;

    if (i % 2 == 0) {
      bigHalf.push(num);
      smallHalf.push(bigHalf.top());
      bigHalf.pop();
    }
    else {
      smallHalf.push(num);
      bigHalf.push(smallHalf.top());
      smallHalf.pop();
    }

    cout << smallHalf.top() << '\n';
  }
}