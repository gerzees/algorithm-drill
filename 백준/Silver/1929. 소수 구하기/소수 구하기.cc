//9:13,9:53
#include<bits/stdc++.h>
using namespace std;
int main(void)
{

	int m, n;
	cin >> m >> n;

	vector<bool> bPrime(1000010, true);
	bPrime[1] = false;
	for (size_t i = 2; i <= 1000000; ++i) {
		if (!bPrime[i]) {
			continue;
		}

		for (size_t j = i * i; j <= 1000000; j += i) {
			bPrime[j] = false;
		}
	}

	for (int i = m; i <= n; ++i) {
		if (bPrime[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}