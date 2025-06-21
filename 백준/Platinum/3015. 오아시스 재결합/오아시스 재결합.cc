#include <bits/stdc++.h>
using namespace std;

int heights[1'000'001];
int n;
long long result;


stack<pair<int, int>> bigger;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> heights[i];
  }

  for (int i = 0; i < n; ++i) {
    //  이번 사람이 서로 볼 수 있는 사람들(작은 사람 스택에서 제거) 모두 쌍 수 계산
    while (bigger.empty() == false && bigger.top().first < heights[i]) {
      result += bigger.top().second;
      bigger.pop();
    }

    // 이전 사람이 없으면 그냥 추가
    if (bigger.empty()) {
      bigger.push({ heights[i],1 });
    }
    // 이전 사람이 이번 사람보다 크면 서로 볼 수 있는 쌍 1 추가
    else if (bigger.top().first > heights[i]) {
      ++result;
      bigger.push({ heights[i],1 });
    }
    // 이전 사람이 이번 사람과 키가 같으면 
    else if (bigger.top().first == heights[i]) {
      // 이전 사람 중 서로 볼 수 있는 더 큰 사람 있다면 쌍 1 추가
      if (bigger.size() > 1) {
        ++result;
      }
      // 같은 키인 사람 수만큼 쌍 추가
      result += bigger.top().second;
      ++bigger.top().second;
    }
  }

  cout << result;
}