// 14:24,14:59
#include<bits/stdc++.h>
using namespace std;

int n;
int a[10000];

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n);
	long long ans = 0ll;

	for (int i = 0; i < n - 2;++i) {
		for (int j = i + 1;j < n - 1; ++j) {
			int target = -(a[i] + a[j]);
			ans += upper_bound(a + j + 1, a + n, target) - lower_bound(a + j + 1, a + n, target);
		}
	}

	cout << ans;

	return 0;
}