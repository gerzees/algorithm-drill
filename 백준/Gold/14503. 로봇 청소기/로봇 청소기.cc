// s 16:27
// e 17:10
#include<bits/stdc++.h>
using namespace std;

int n, m;
int r, c;
int d;//0:north, 1:east, 2:south, 3:west
int room[51][51];
bool bCleaned[51][51];
int ans;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main(void)
{
	cin >> n >> m >> r >> c >> d;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> room[i][j];
		}
	}

	while (true) {
		if (!bCleaned[r][c]) {
			bCleaned[r][c] = true;
			++ans;
		}

		bool bCleanedAround = true;

		for (int i = 0; i < 4; ++i) {
			d = d == 0 ? 3 : d - 1;
			int nr = r + dr[d];
			int nc = c + dc[d];

			if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
				continue;
			}

			if (room[nr][nc] != 0) { //wall
				continue;
			}

			if (!bCleaned[nr][nc]) {
				bCleanedAround = false;
				r = nr;
				c = nc;
				break;
			}
		}

		if (bCleanedAround) {
			int back = d < 2 ? d + 2 : d - 2;
			int nr = r + dr[back];
			int nc = c + dc[back];

			if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
				break;
			}

			if (room[nr][nc] != 0) {
				break;
			}

			r = nr;
			c = nc;
		}
	}

	cout << ans;

	return 0;
}