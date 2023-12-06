//23:27,1:33
#include<bits/stdc++.h>
using namespace std;
int n;
long long s;
long long a[100010];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	int ans = n + 1;

	for (int i = 1; i <= n;++i) {
		int idx = lower_bound(a + i, a + n + 1, a[i - 1] + s) - a;
		if (idx == n + 1) {
			continue;
		}

		ans = min(ans, idx - i + 1);
	}

	if (ans == n + 1) {
		cout << 0;

		return 0;
	}

	cout << ans;

	return 0;
}