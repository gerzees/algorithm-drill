// s 22:16
// e 23:09
#include <bits/stdc++.h>

using namespace std;
int D[1000001];

int dpRecursive(int n)
{
	if (n == 1 || D[n] != 0) {
		return D[n];
	}

	int min = dpRecursive(n - 1);

	if (n % 3 == 0) {
		if (min > dpRecursive(n / 3)) {
			min = dpRecursive(n / 3);
		}
	}

	if (n % 2 == 0) {
		if (min > dpRecursive(n / 2)) {
			min = dpRecursive(n / 2);
		}
	}

	D[n] = min + 1;
	return D[n];
}

int main(void)
{
	int N;
	cin >> N;

	cout << dpRecursive(N);

	return 0;
}