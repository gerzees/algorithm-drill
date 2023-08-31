// start 20:29
// end 21:09
#include <bits/stdc++.h>

using namespace std;

int drawing[500][500];
bool bVisited[500][500];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;//세로 1<=<=500
	int m;//가로 1<=<=500
	cin >> n >> m;

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			cin >> drawing[r][c];
		}
	}
	int maxSize = 0;
	int drawingCount = 0;

	for (int r = 0;r < n;++r) {
		for (int c = 0;c < m;++c) {
			if (bVisited[r][c]) {
				continue;
			}

			if (drawing[r][c] == 0) {
				bVisited[r][c] = true;
				continue;
			}

			++drawingCount;
			queue<pair<int, int>> Q;
			Q.push(make_pair(r, c));
			bVisited[r][c] = true;
			int drawingSize = 1;
			const int dr[] = { 1,-1,0,0 };
			const int dc[] = { 0,0,1,-1 };

			while (!Q.empty()) {
				int currentR = Q.front().first;
				int currentC = Q.front().second;
				Q.pop();

				for (int i = 0;i < 4;++i) {
					int nextR = currentR + dr[i];
					int nextC = currentC + dc[i];

					if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m) {

						if (!bVisited[nextR][nextC]) {
							bVisited[nextR][nextC] = true;

							if (drawing[nextR][nextC] == 1) {
								Q.push(make_pair(nextR, nextC));
								++drawingSize;
							}
						}
					}
				}
			}

			if (drawingSize > maxSize) {
				maxSize = drawingSize;
			}
		}
	}

	cout << drawingCount << '\n' << maxSize;

	return 0;
}