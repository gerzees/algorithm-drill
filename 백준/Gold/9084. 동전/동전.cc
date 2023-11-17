// 12:37-14:06
// 테이블 d[i]: i원 만드는 방법의 수
// d[i] += d[i - a[j]] a[j]원인 동전을 추가하면 방법의 수가 얼마나 늘어나는지. a[j] 모자란 금액 만드는 방법의 수를 현재 금액 만드는 방법의 수에 누적한다.
// d[a[j]] += 1 a[j]원은 a[j]원 동전 하나 사용해서 만들 수 있으니 1(가지) 누적.
// a[j]이상 원하는 금액이하 순회하면서 누적. 각 동전마다 반복해서 방법의 수 누적.
// 순회 끝나면, d[원하는 금액]=원하는 금액 만드는 방법의 수
#include<bits/stdc++.h>
using namespace std;

int d[10010];
int coins[22];

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> coins[i];
		}
		int m;
		cin >> m;

		for (int i = 0; i < n; ++i) {
			d[coins[i]] += 1;
			for (int j = coins[i] + 1; j <= m; ++j) {
				d[j] += d[j - coins[i]];
			}
		}

		cout << d[m] << '\n';

		fill(coins, coins + n, 0);
		fill(d, d + 10010, 0);
	}
	return 0;
}