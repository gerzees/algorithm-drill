// 8:52, 9:00
#include<bits/stdc++.h>
using namespace std;
bool bPrime[1001];
int main(void)
{
	fill(bPrime + 2, bPrime + 1001, true);
	for (int i = 2; i <= 1000; ++i) {
		if (!bPrime[i]) {
			continue;
		}

		for (int j = 2; i * j <= 1000; ++j) {
			if (!bPrime[i * j]) {
				continue;
			}

			bPrime[i * j] = false;
		}
	}

	int ans = 0;
	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		if (bPrime[num]) {
			++ans;
		}
	}

	cout << ans;

	return 0;
}