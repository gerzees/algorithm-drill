// 7:45, 8:10
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int m, n;
pair<int, int> multiverse[100][10000];
int orders[100][10000];
int main(void)
{
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int planetSize;
			cin >> planetSize;
			multiverse[i][j].X = planetSize;
			multiverse[i][j].Y = j;
		}
	}

	for (int i = 0; i < m; ++i) {
		sort(multiverse[i], multiverse[i] + n);
	}

	for (int i = 0; i < m; ++i) {
		int order = 0;
		orders[i][multiverse[i][0].Y] = order;
		for (int j = 1; j < n; ++j) {
			const pair<int, int>& prev = multiverse[i][j - 1];
			const pair<int, int>& cur = multiverse[i][j];

			if (prev.X == cur.X) {
				orders[i][cur.Y] = order;
			}
			else {
				orders[i][cur.Y] = ++order;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			bool bEqual = true;

			for (int k = 0; k < n; ++k) {
				if (orders[i][k] != orders[j][k]) {
					bEqual = false;
					break;
				}
			}

			if (bEqual) {
				++ans;
			}
		}
	}

	cout << ans;

	return 0;
}