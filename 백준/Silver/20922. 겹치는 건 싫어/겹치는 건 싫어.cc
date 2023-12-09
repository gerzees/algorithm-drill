//12:32,12:50
#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[200'000];
int cnt[100'001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int en = 0;
	int mx = 0;

	for (int st = 0; st < n; ++st) {
		while (en < n && cnt[a[en]] < k) {
			++cnt[a[en]];
			++en;
		}

		mx = max(mx, en - st);

		if (en == n) {
			break;
		}

		while (st < n && a[st] != a[en]) {
			--cnt[a[st]];
			++st;
		}
		--cnt[a[st]];
	}

	cout << mx;


	return 0;
}