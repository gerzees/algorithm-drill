// s 13:46
// e 13:58
// 테이블(배열), 점화식, 초기조건
// d[i] = 1번째부터 i번째 수까지의 합
// i번째부터 j번째까지 수 합 = d[j]-d[i-1]
#include <bits/stdc++.h>
using namespace std;
int d[100001];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		int num;
		cin >> num;
		d[i] = d[i - 1] + num;
	}

	for (int k = 0; k < m; ++k) {
		int i;
		int j;
		cin >> i >> j;
		cout << d[j] - d[i - 1] << '\n';
	}

	return 0;
}