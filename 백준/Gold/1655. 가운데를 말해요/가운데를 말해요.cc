// 8:51, 9:38
#include<bits/stdc++.h>
using namespace std;

priority_queue<int> smallHalf;
priority_queue<int, vector<int>, greater<>> bigHalf;
int N, num;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while (N--) {
    cin >> num;

    smallHalf.push(num);
    bigHalf.push(smallHalf.top());
    smallHalf.pop();
    int middle = bigHalf.top();
    bigHalf.pop();

    if (smallHalf.size() == bigHalf.size()) {
      smallHalf.push(middle);
    }
    else {
      bigHalf.push(middle);
    }

    cout << smallHalf.top() << '\n';
  }
}