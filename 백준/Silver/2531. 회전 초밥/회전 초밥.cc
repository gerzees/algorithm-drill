//11:53,12:22
#include<bits/stdc++.h>
using namespace std;

int n;
int d;
int k;
int c;
int a[60000];
vector<int> cnt(3001);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
	}

	int kind = 0;
	for (int i = 0; i < k; ++i) {
		if (cnt[a[i]] == 0) {
			++kind;
		}

		++cnt[a[i]];
	}

	int mx = kind + (cnt[c] == 0 ? 1 : 0);

	int en = k;
	for (int st = 0; st < n; ++st, ++en) {
		if (cnt[a[en]] == 0) {
			++kind;
		}

		++cnt[a[en]];
		--cnt[a[st]];

		if (cnt[a[st]] == 0) {
			--kind;
		}

		mx = max(mx, kind + (cnt[c] == 0 ? 1 : 0));
	}

	cout << mx;


	return 0;
}