//14:38,15:18
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[1000] = {};
	vector<int> two;
	two.reserve(1000000);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n, greater<int>());


	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			two.push_back(a[i] + a[j]);
		}
	}

	sort(two.begin(), two.end());

	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (binary_search(two.begin(), two.end(), a[i] - a[j])) {
				cout << a[i];

				return 0;
			}
		}
	}

	return 0;
}