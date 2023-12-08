//10:31, 10:56
#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
vector<bool> bP(4000001, true);

int main(void)
{
	for (int n = 2; n * n <= 4000000; ++n) {
		if (!bP[n])
			continue;

		for (int i = n + n; i <= 4000000; i += n) {
			bP[i] = false;
		}
	}

	for (int n = 2; n <= 4000000; ++n) {
		if (!bP[n])
			continue;

		primes.push_back(n);
	}

	int N;
	cin >> N;

	int en = 0;
	int s = primes[0];
	int cnt = 0;
	for (int st = 0; st < primes.size(); ++st) {
		while (en < primes.size() && s < N) {
			++en;
			if (en != primes.size())
				s += primes[en];
		}

		if (en == primes.size() && primes[en] > N)
			break;

		if (s == N) {
			++cnt;
		}

		s -= primes[st];
	}

	cout << cnt;

	return 0;
}