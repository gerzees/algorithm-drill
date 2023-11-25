//18:06,17:10 + 18:39,19:00 해설 읽고 구현
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}

	return gcd(b % a, a);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int ans = 1;
		int i;
		int limit = m < n ? lcm(m, n) : lcm(n, m);
		for (i = x; i <= limit;i += m) {
			if (i % n == y % n) {
				break;
			}
		}

		if (i > limit) {
			cout << -1 << '\n';
		}
		else {
			cout << i << '\n';
		}
	}

	return 0;
}