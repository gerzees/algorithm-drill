#include<bits/stdc++.h>
using namespace std;
int a[12];

int main(void)
{
	int n;
	int k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int cnt = 0;

	for (int i = n - 1; i >= 0; --i) {
		cnt += k / a[i];
		k %= a[i];
	}

	cout << cnt;

	return 0;
}