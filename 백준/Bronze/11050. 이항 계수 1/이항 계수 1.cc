#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, k;
	cin >> n >> k;
	int ans = 1;
	for (int i = 0; i < k; ++i) {
		ans *= (n - i);
	}
	for (int i = 0; i < k; ++i) {
		ans /= (k - i);
	}

	cout << ans;

	return 0;
}