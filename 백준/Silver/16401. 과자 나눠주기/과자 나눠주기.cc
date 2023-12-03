// 8:39, 8:51
// N개의 과자로 M개의 과자 만들 때 과자 길이 최대?
// N개의 과자로 만드는 새 과자 길이 x일 때 M개의 과자 만들 수 있나?
#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int m, n;

bool canMake(long long len)
{
	long long cnt = 0;

	for (int i = 0; i < n; ++i) {
		cnt += a[i] / len;
	}

	return cnt >= m;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	long long sum = 0;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	if (m > sum) {
		cout << 0;

		return 0;
	}

	long long st = 1;
	long long en = 1000000000;
	while (st < en) {
		long long mid = (st + en + 1) / 2;

		if (canMake(mid)) {
			st = mid;
		}
		else {
			en = mid - 1;
		}
	}

	cout << st;

	return 0;
}