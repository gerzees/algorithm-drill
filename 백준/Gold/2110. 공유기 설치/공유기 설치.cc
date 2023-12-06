// 8:38,9:02
// 가장 인접한 두 공유기 사이 거리 최대
// 두 공유기 사이 거리 x일 때 c개의 공유기 n개의 집에 설치 가능?
#include<bits/stdc++.h>
using namespace std;

int n;
int c;
int x[200000];

bool solve(int dist)
{
	int prev = 0;
	int cnt = 1;

	for (int cur = 1; cur < n; ++cur) {
		if (x[cur] - x[prev] < dist) {
			continue;
		}

		++cnt;
		prev = cur;
	}

	return cnt >= c;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}

	sort(x, x + n);

	int st = 0;
	int en = (int)1e9;

	while (st < en) {
		int mid = (st + en + 1) / 2;

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