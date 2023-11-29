//8:15, 9:15
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int d[11][10] = {};
	for (int j = 0;j < 10;++j) {
		d[1][j] = 1;
	}
	for (int i = 1; i < 10; ++i) {
		int sum = 0;
		for (int j = 0; j < 9; ++j) {
			sum += d[i][j];
			d[i + 1][j + 1] = sum;
		}
	}

	int n;
	cin >> n;
	++n;

	int len = -1;
	int num = 0;
	bool bFound = false;
	for (int i = 1; i < 11 && !bFound; ++i) {
		for (int j = 0; j < 10 && !bFound; ++j) {
			if (n > d[i][j]) {
				n -= d[i][j];
				continue;
			}

			len = i;
			num = j;
			bFound = true;
		}
	}

	if (!bFound) {
		cout << -1;

		return 0;
	}

	while (true) {
		cout << num;
		--len;
		if (len == 0) {
			return 0;
		}

		for (int j = 0; j < 10; ++j) {
			if (n <= d[len][j]) {
				num = j;
				break;
			}

			n -= d[len][j];
		}
	}

	return 0;
}