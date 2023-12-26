// 20:42, 21:09
#include<bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while (N--) {
    int deckSize;
    cin >> deckSize;
    pq.push(deckSize);
  }

  int ans = 0;
  while (true) {
    int deck1, deck2;
    deck1 = pq.top();
    pq.pop();

    if (pq.empty())
      break;

    deck2 = pq.top();
    pq.pop();
    pq.push(deck1 + deck2);
    ans += deck1 + deck2;
  }

  cout << ans;
}