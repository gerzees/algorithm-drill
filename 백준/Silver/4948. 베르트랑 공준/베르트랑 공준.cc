// 9:42, 9:58
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	const int limit = 123456 * 2 + 5;
	vector<bool> bPrime(limit, true);
	bPrime[1] = false;
	for (int n = 2; n * n < limit;++n) {
		if (!bPrime[n]) {
			continue;
		}

		for (int i = n * n; i < limit; i += n) {
			bPrime[i] = false;
		}
	}

	while (true) {
		int n;
		cin >> n;

		if (n == 0) {
			break;
		}

		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; ++i) {
			if (bPrime[i]) {
				++cnt;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}