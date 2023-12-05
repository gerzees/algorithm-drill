// 8:11,9:37
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
int a[100000];

int solve(int target)
{
	int st = target + 1;
	int en = n - 1;

	while (en - st > 1) {
		int mid = (st + en) / 2;

		if (a[target] + a[mid] == 0) {
			return mid;
		}

		if (a[target] + a[mid] > 0) {
			en = mid;
		}
		else {
			st = mid;
		}
	}

	int stSol = a[st] + a[target];
	if (stSol < 0) {
		stSol = -stSol;
	}

	int enSol = a[en] + a[target];
	if (enSol < 0) {
		enSol = -enSol;
	}

	if (stSol < enSol) {
		return st;
	}

	return en;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int zeroSol = 2000000001;
	pair<int, int> zeroPair;
	for (int i = 0; i < n - 1; ++i) {
		int pairedSol = solve(i);
		int newSol = a[i] + a[pairedSol];

		if (newSol == 0) {
			cout << a[i] << ' ' << a[pairedSol];

			return 0;
		}

		bool bNewZeroSol = newSol > 0 ? newSol <= zeroSol : -newSol <= zeroSol;

		if (bNewZeroSol) {
			zeroSol = abs(newSol);
			zeroPair.X = i;
			zeroPair.Y = pairedSol;
		}
	}

	cout << a[zeroPair.X] << ' ' << a[zeroPair.Y];

	return 0;
}