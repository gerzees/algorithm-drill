// s 12;18
// e 14:45
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r, c;
	cin >> n >> r >> c;
	int ans = 0;

	for (int i = n - 1; i >= 0; --i) {
		int mask = 1 << i;
		ans <<= 1;

		if (r & mask) {
			ans |= 1;
		}

		ans <<= 1;

		if (c & mask) {
			ans |= 1;
		}
	}

	cout << ans;

	return 0;
}