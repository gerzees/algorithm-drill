// 9:34,9:50
#include<bits/stdc++.h>
using namespace std;

int n, offset, sum, mean;
int opinions[300'001];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  if (n == 0) {
    cout << 0;

    return 0;
  }

  for (int i = 0; i < n; ++i) {
    cin >> opinions[i];
  }

  sort(opinions, opinions + n);
  offset = n * 15 / 100;

  if (n * 15 / 10 % 10 >= 5)
    ++offset;

  for (int i = offset; i < n - offset; ++i) {
    sum += opinions[i];
  }

  mean = sum / (n - 2 * offset);

  if (sum * 10 / (n - 2 * offset) % 10 >= 5)
    ++mean;

  cout << mean;
}