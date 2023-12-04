// 8:58, 9:16
// M 나무 얻을 수 있는 절단기 높이 최대
// 높이 x로 했을 때 M 나무 얻을 수 있나?
#include<bits/stdc++.h>
using namespace std;

int n, m;
int tHeight[1000000];

bool solve(long long height)
{
	long long len = 0;

	for (int i = 0; i < n; ++i) {
		if (tHeight[i] > height) {
			len += tHeight[i] - height;
		}
	}

	return len >= m;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> tHeight[i];
	}

	long long st = 0;
	long long en = 1000000000;

	while (st < en) {
		long long mid = (st + en + 1) / 2;

		if (solve(mid)) {
			st = mid;
		}
		else {
			en = mid - 1;
		}
	}

	cout << st;

	return 0;
}