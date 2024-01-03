// 14:38, 15:02
#include<bits/stdc++.h>
using namespace std;

unordered_set<string> noHear;
priority_queue<string,vector<string>,greater<>> noHearAndNoSee;
int N, M;
string name;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  while (N--) {
    cin >> name;
    noHear.insert(name);
  }

  while (M--) {
    cin >> name;
    if (noHear.find(name) != noHear.end())
      noHearAndNoSee.push(name);
  }

  cout << noHearAndNoSee.size() << '\n';
  while (!noHearAndNoSee.empty()) {
    cout << noHearAndNoSee.top() << '\n';
    noHearAndNoSee.pop();
  }
}