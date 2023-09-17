// s 8:51 11:37
// e 8:56 11:45
#include <bits/stdc++.h>
using namespace std;
//unsigned long long r[100];

int powerAndMod(int base, int index, int mod)
{
	if (index == 1) {
		return base % mod;
	}

	int i = index / 2;
	int m = index % 2;

	unsigned long long r = powerAndMod(base, i, mod);
	r = r * r % mod;
	
	if (m) {
		r = r * (base % mod) % mod;
	}

	return r % mod;
}

int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;
	cout << powerAndMod(A, B, C);
	return 0;
}