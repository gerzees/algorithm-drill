//9:55,10:28
#include<bits/stdc++.h>
using namespace std;

int n;
int m;
int a[100000];

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n);
	m = abs(m);
	int diff = (int)2e9;

	for (int i = 0; i < n - 1; ++i) {
		int idx = lower_bound(a + i, a + n, a[i] + m) - a;
		if (idx == n) {
			continue;
		}

		diff = min(diff, a[idx] - a[i]);
		if (diff == m) {
			cout << m;

			return 0;
		}
	}

	cout << diff;

	return 0;
}