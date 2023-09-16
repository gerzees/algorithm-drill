// s 16:40
// e 22:36
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[201][201];
int dist[201][201][31];

const int dx[12] = { 1,-1,0,0,2,1,-1,-2,-2,-1,1,2 };
const int dy[12] = { 0,0,1,-1,1,2,2,1,-1,-2,-2,-1 };
const int dMoveCount[12] = { 0,0,0,0,1,1,1,1,1,1,1,1 };
const int ALL_DIRECTION = 12;
const int FOUR_DIRECTION = 4;

int main(void)
{
	int K, W, H;
	cin >> K >> W >> H;

	for (int i = 0;i < H;++i) {

		for (int j = 0;j < W;++j) {

			cin >> board[i][j];
			fill(dist[i][j], dist[i][j] + K + 1, -1);
		}
	}

	queue<tuple<int, int, int> > Q;
	Q.push({ 0,0,0 });
	dist[0][0][0] = 0;

	while (!Q.empty()) {
		int x, y, knightMoveCount;
		tie(x, y, knightMoveCount) = Q.front();
		Q.pop();

		if (x == H - 1 && y == W - 1) {
			cout << dist[x][y][knightMoveCount];
			return 0;
		}

		int dirCount = knightMoveCount < K ? ALL_DIRECTION : FOUR_DIRECTION;

		for (int i = 0;i < dirCount;++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nMoveCount = knightMoveCount + dMoveCount[i];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
				continue;
			}

			if (dist[nx][ny][nMoveCount] != -1 || board[nx][ny] == 1) {
				continue;
			}

			Q.push({ nx,ny,nMoveCount });
			dist[nx][ny][nMoveCount] = dist[x][y][knightMoveCount] + 1;
		}
	}

	cout << -1;

	return 0;
}