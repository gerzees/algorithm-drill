//13:31,14:00
#include<bits/stdc++.h>
using namespace std;

int n, m, a[100005];

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int cnt = 0;
	int st = 0;
	int en = 0;
	int s = a[0];

	while (en < n) {
		if (s < m) {
			s += a[++en];
		}
		if (s == m) {
			++cnt;
			s -= a[st++];
		}
		else if (s > m) {
			s -= a[st++];
		}
	}

	cout << cnt;

	return 0;
}