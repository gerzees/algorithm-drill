// s 23:23
// e 23:57
#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;
int cntQMove[15][15];

void locateRecursive(int r)
{
	if (r == n) {
		++cnt;
		return;
	}

	for (int c = 0;c < n;++c) {
		if (cntQMove[r][c] == 0) {
			for (int i = 1;i < n - r;++i) {
				++cntQMove[r + i][c];
				if (c + i < n) {
					++cntQMove[r + i][c + i];
				}
				if (c - i >= 0) {
					++cntQMove[r + i][c - i];
				}
			}

			locateRecursive(r + 1);

			for (int i = 1;i < n - r;++i) {
				--cntQMove[r + i][c];
				if (c + i < n) {
					--cntQMove[r + i][c + i];
				}
				if (c - i >= 0) {
					--cntQMove[r + i][c - i];
				}
			}
		}
	}
}

int main(void)
{
	cin >> n;
	locateRecursive(0);
	cout << cnt;
	return 0;
}