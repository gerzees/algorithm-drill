//14:07, 14:22
#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int sorted[1000000];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 0;i < n;++i) {
		cin >> a[i];
	}

	for (int i = 0;i < n;++i) {
		sorted[i] = a[i];
	}

	sort(sorted, sorted + n);

	int cnt = 1;

	for (int i = 1; i < n;++i) {
		if (sorted[cnt - 1] == sorted[i]) {
			continue;
		}

		sorted[cnt] = sorted[i];
		++cnt;
	}

	for (int i = 0; i < n; ++i) {
		cout << lower_bound(sorted, sorted + cnt, a[i]) - sorted << ' ';
	}

	return 0;
}