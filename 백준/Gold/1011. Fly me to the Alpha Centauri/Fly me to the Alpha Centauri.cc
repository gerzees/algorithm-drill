//16:15, 16:32
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;

		int dist = y - x;

		int cnt = 0;
		for (int k = 1;dist > k;++k) {
			dist -= k;
			++cnt;
			if (dist <= k) {
				break;
			}
			dist -= k;
			++cnt;
		}
		++cnt;

		cout << cnt << '\n';
	}

	return 0;
}