//10:11, 10:20
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int p[1005];

	for (int i = 0;i < n;++i) {
		cin >> p[i];
	}

	sort(p, p + n);
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		ans += p[i] * (n - i);
	}

	cout << ans;

	return 0;
}