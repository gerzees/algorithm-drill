#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  chrono::time_point tp = chrono::system_clock::now();
  tp += chrono::duration<long long, ratio<3600>>(9);
  time_t t = chrono::system_clock::to_time_t(tp);
  cout << put_time(gmtime(&t), "%Y-%m-%d");
  return 0;
}