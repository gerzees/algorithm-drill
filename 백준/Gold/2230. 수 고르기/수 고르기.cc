//9:36,9:55
#include<bits/stdc++.h>
using namespace std;

int n, m, a[100000];

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n);

	int st, en;
	st = en = 0;
	int minDif = 0x7fffffff;

	while (st < n) {

		while (en != n - 1 && a[en] - a[st] < m) {
			++en;
		}

		if (a[en] - a[st] >= m) {
			minDif = min(minDif, a[en] - a[st]);
		}

		++st;
	}

	cout << minDif;

	return 0;
}