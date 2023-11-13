//s 10:07
//e 10:17
// 테이블(배열) d[i][0]: f(i)가 출력하는 0 횟수, d[i][1]: f(i)가 출력하는 1 횟수
// 점화식 d[i][x] = d[i-1][x]+d[i-2][x] (i>=2)
// 초기조건 d[0][0] = 1, d[0][1] = 0, d[1][0] = 0, d[1][1] = 1
#include <bits/stdc++.h>
using namespace std;

int d[41][2];
int main(void)
{
	d[0][0] = 1;
	d[0][1] = 0;
	d[1][0] = 0;
	d[1][1] = 1;
	for (int i = 2; i <= 40; ++i) {
		for (int j = 0;j < 2; ++j) {
			d[i][j] = d[i - 1][j] + d[i - 2][j];
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << d[n][0] << ' ' << d[n][1] << '\n';
	}

	return 0;
}