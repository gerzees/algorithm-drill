//20:27-20:55
// 테이블: d[i] i일까지의 상담중 i일의 상담을 포함하여 상담 계획을 세운 경우 중 최대 이익/ 퇴사해서 없는 경우 상담을 할 수 없으므로 상담이 불가능한 경우도 있는데
// 점화식: d[i] = 상담이 가능하면 가능한 d[j]중 최대에 p[i] 더한다(j<i)/ 상담이 불가능하면 0
// 초기 조건 d[1] = a[1]
// d[i] 중 최대 값이 얻을 수 있는 최대 이익
#include<bits/stdc++.h>
using namespace std;

int d[16];
int t[16];
int p[16];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> p[i];
	}

	d[1] = p[1];

	if (t[1] + 1 > n + 1) {
		d[1] = 0;
	}

	for (int i = 2; i <= n; ++i) {
		if (i + t[i] - 1 >= n + 1) {
			continue;
		}

		d[i] = p[i];

		for (int j = 1; j < i; ++j) {
			if (j + t[j] - 1 >= i) {
				continue;
			}

			d[i] = max(d[i], d[j] + p[i]);
		}
	}

	cout << *max_element(d + 1, d + 1 + n);

	return 0;
}