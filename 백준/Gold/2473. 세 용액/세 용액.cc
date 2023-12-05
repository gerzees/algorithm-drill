// 15:02, 15:19
#include<bits/stdc++.h>
using namespace std;

int n;
int a[5000];
int ans[3];
int di[3] = { -1,0,1 };
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n);

	long long ansSol = (long long)3e9 + 1ll;

	for (int i = 0; i < n - 2;++i) {
		for (int j = i + 1;j < n - 1; ++j) {
			long long cur = (long long)a[i] + (long long)a[j];
			int idx = lower_bound(a + j + 1, a + n, -cur) - a;

			for (int k = 0;k < 3;++k) {
				if (idx + di[k] <= j || idx + di[k] >= n) {
					continue;
				}

				long long sol = abs(cur + a[idx + di[k]]);

				if (sol < ansSol) {
					ansSol = sol;
					ans[0] = a[i];
					ans[1] = a[j];
					ans[2] = a[idx + di[k]];
				}

				if (sol == 0) {
					cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];

					return 0;
				}
			}
		}
	}

	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];

	return 0;
}