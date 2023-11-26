// 11:47, 11:55
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tCnt = 0;
	int l, p, v;

	while (true) {
		cin >> l >> p >> v;
		
		if (l == 0 && p == 0 && v == 0) {
			break;
		}

		++tCnt;
		int ans = v / p * l + (v % p >= l ? l : v % p);

		cout << "Case " << tCnt << ": " << ans << '\n';
	}

	return 0;
}