// s 16:07
// e 17:34
#include<bits/stdc++.h>
using namespace std;

int planes[5][5][5];
int dist[5][5][5];
tuple<int, int, int> entrance[4] = { {0,0,0},{0,4,0},{0,0,4},{0,4,4} };
tuple<int, int, int> wayOut[4] = { {4,4,4},{4,0,4},{4,4,0},{4,0,0} };
int layers[5] = { 0,1,2,3,4 };
int dl[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { 0,0,0,0,-1,1 };
unsigned int ans = -1;

int main(void)
{
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				cin >> planes[i][j][k];
			}
		}
	}

	for (int i = 0; i < (1 << 2 * 5); ++i) {
		int packedDir = i;
		for (int j = 0;j < 5;++j) {
			int dir = packedDir & 3;
			packedDir >>= 2;
			for (int k = 0; k < dir; ++k) {
				//rotatePlane(j, dir);
				int tmp[5][5] = {};
				for (int l = 0; l < 5; ++l) {
					for (int m = 0; m < 5; ++m) {
						tmp[m][4 - l] = planes[j][l][m];
					}
				}

				for (int l = 0; l < 5; ++l) {
					for (int m = 0; m < 5; ++m) {
						planes[j][l][m] = tmp[l][m];
					}
				}
			}
		}

		do {
			for (int j = 0; j < 4; ++j) {
				int goalL, goalX, goalY;
				tie(goalL, goalX, goalY) = wayOut[j];

				if (planes[layers[goalL]][goalX][goalY] == 0) {
					continue;
				}

				queue<tuple<int, int, int>> Q;
				fill(dist[0][0], dist[0][0] + 125, -1);

				{
					int l, x, y;
					tie(l, x, y) = entrance[j];

					if (planes[layers[l]][x][y] == 0) {
						continue;
					}

					Q.push({ l,x,y });
					dist[l][x][y] = 0;
				}

				while (!Q.empty()) {
					int l, x, y;
					tie(l, x, y) = Q.front();
					Q.pop();

					if (l == goalL && x == goalX && y == goalY) {
						if (dist[l][x][y]==12) {
							cout << 12;
							return 0;
						}

						if (ans > dist[l][x][y]) {
							ans = dist[l][x][y];
						}

						break;
					}

					for (int k = 0; k < 6; ++k) {
						int nl = l + dl[k];
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nl < 0 || nl >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5) {
							continue;
						}

						if (planes[layers[nl]][nx][ny] == 0) {
							continue;
						}

						if (dist[nl][nx][ny] != -1) {
							continue;
						}

						Q.push({ nl,nx,ny });
						dist[nl][nx][ny] = dist[l][x][y] + 1;
					}
				}

			}
		} while (next_permutation(layers, layers + 5));
	}

	cout << (int)ans;

	return 0;
}