//13:54,13:05
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if (a == 0) {
		return b;
	}

	return gcd(b % a, a);
}

int main(void)
{
	int r[100] = {};
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> r[i];
	}

	for (int i = 1;i < n;++i) {
		int curGcd = gcd(r[0], r[i]);

		cout << r[0] / curGcd << '/' << r[i] / curGcd << '\n';
	}

	return 0;
}