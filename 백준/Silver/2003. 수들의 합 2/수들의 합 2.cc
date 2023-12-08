//13:31,13:46
#include<bits/stdc++.h>
using namespace std;

int n, m, a[100000];

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int cnt = 0;
	int en = 0;
	int s = a[0];

	for (int st = 0; st < n; ++st) {
		while (en < n && s < m) {
			++en;
			if (en != n) {
				s += a[en];
			}
		}

		if (en == n) {
			break;
		}

		if (s == m) {
			++cnt;
		}

		s -= a[st];
	}

	cout << cnt;

	return 0;
}