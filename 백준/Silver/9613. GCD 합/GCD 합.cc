//9:45, 10:13
#include<bits/stdc++.h>
using namespace std;

int num[105];

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}

	return gcd(b % a, a);
}

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> num[i];
		}

		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				ans += gcd(num[i], num[j]);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}