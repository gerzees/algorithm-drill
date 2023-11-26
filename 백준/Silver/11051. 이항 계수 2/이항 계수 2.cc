// 11:25, 11:38해설 보고 구현
#include<bits/stdc++.h>
using namespace std;

int d[1010];
int main(void)
{
	const int MOD = 10007;
	int n, k;
	d[0] = 1;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		for (int j = i; j > 0;--j) {
			d[j] = d[j] + d[j - 1];
			d[j] %= MOD;
		}
	}

	cout << d[k];

	return 0;
}