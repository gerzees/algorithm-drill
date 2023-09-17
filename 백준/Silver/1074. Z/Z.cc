// s 12;18
// e 14:22
#include <bits/stdc++.h>

using namespace std;

int getDistRecursive(int n, int r, int c)
{
	if (n == 0) {
		return 0;
	}
	int half = 1 << (n - 1);

	int countQuarter = half * half;

	if (r < half && c < half) {//LeftTop
		return getDistRecursive(n - 1, r, c);
	}
	if (r < half) {//RightTop
		return countQuarter + getDistRecursive(n - 1, r, c - half);
	}
	if (c < half) {//LeftBottom
		return 2 * countQuarter + getDistRecursive(n - 1, r - half, c);
	}
	return 3 * countQuarter + getDistRecursive(n - 1, r - half, c - half);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r, c;
	cin >> n >> r >> c;

	cout << getDistRecursive(n, r, c);

	return 0;
}