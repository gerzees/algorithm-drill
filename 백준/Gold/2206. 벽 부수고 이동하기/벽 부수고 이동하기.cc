// s 12:46
// e 14:20
#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int dist[1001][1001];
int distBroken[1001][1001];
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int main(void)
{
	int n;
	int m;
	cin >> n >> m;

	for (int i = 0;i < n;++i) {
		string line;
		cin >> line;

		for (int j = 0;j < m;++j) {
			switch (line[j]) {
			case '0':
				board[i][j] = 0;
				break;
			case '1':
				board[i][j] = 1;
				break;
			default:
				assert(false);
				break;
			}
		}
	}

	queue<tuple<int, int, int> > Q;
	Q.push({ 0,0,0 });
	dist[0][0] = 1;

	while (!Q.empty()) {
		tuple<int, int, int> cur = Q.front();
		Q.pop();

		int x = get<0>(cur);
		int y = get<1>(cur);
		int countWallBreak = get<2>(cur);

		if (x == n - 1 && y == m - 1) {
			if (countWallBreak == 0) {
				cout << dist[x][y];
			}
			else {
				cout << distBroken[x][y];
			}

			return 0;
		}

		for (int i = 0;i < 4;++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			if (dist[nx][ny] != 0) {
				continue;
			}

			if (countWallBreak > 0) {
				if (board[nx][ny] == 1) {
					continue;
				}

				if (distBroken[nx][ny] > 0) {
					continue;
				}

				Q.push({ nx,ny,countWallBreak });
				distBroken[nx][ny] = distBroken[x][y] + 1;
			}
			else {

				if (board[nx][ny] == 1) {
					Q.push({ nx,ny,countWallBreak + 1 });
					dist[nx][ny] = dist[x][y] + 1;
					distBroken[nx][ny] = dist[x][y] + 1;
				}
				else {
					Q.push({ nx,ny,countWallBreak });
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}
	}

	cout << -1;

	return 0;
}