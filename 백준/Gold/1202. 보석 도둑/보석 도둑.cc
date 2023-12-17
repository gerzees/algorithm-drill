// 11:48, 12:40
#include<bits/stdc++.h>
using namespace std;

int n, k;
int c[300'000];
pair<int, int> jewel[300'000];
multiset<int> ms;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		int m, v;
		cin >> m >> v;
		jewel[i] = { m,v };
	}

	for (int i = 0; i < k; ++i) {
		cin >> c[i];
	}

	sort(c, c + k);
	sort(jewel, jewel + n);

	long long tot = 0;
	int j = 0;

	for (int i = 0; i < k; ++i) {

		while (j < n && c[i] >= jewel[j].first) {
			ms.insert(jewel[j].second);
			++j;
		}

		if (ms.empty()) continue;

		tot += *prev(ms.end());
		ms.erase(prev(ms.end()));
	}

	cout << tot;
}