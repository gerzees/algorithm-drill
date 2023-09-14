//s 12:56
//e 13:49
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[101][101];
int dist[101][101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int main(void)
{
	int N;
	cin >> N;
	queue<pair<int, int> > Q;
	queue<tuple<int, int, int> > bridgeQ;
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			int bLand;
			cin >> bLand;

			if (bLand) {
				board[i][j] = -1;
				Q.push({ i,j });
			}
		}
	}

	int landSize = Q.size();
	int landNum = 0;
	while (landSize--) {
		pair<int, int>& landPart = Q.front();
		Q.pop();

		if (board[landPart.X][landPart.Y] > 0) {
			continue;
		}

		++landNum;
		queue<pair<int, int> > landQ;
		board[landPart.X][landPart.Y] = landNum;
		landQ.push(landPart);

		while (!landQ.empty()) {
			pair<int, int>& cur = landQ.front();
			landQ.pop();

			for (int i = 0;i < 4;++i) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
					continue;
				}

				if (board[nx][ny] > 0) {
					continue;
				}

				if (board[nx][ny] == -1) {
					board[nx][ny] = landNum;
					landQ.push({ nx,ny });
				}
				else if (dist[nx][ny][landNum] == 0) {
					dist[nx][ny][landNum] = 1;
					bridgeQ.push({ nx,ny,landNum });
				}
			}
		}
	}

	while (!bridgeQ.empty()) {
		int x, y, land;
		tie(x, y, land) = bridgeQ.front();
		bridgeQ.pop();

		for (int i = 0;i < 4;++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
				continue;
			}

			if (dist[nx][ny][land] != 0) {
				continue;
			}

			if (board[nx][ny] == land) {
				continue;
			}

			if (board[nx][ny] == 0) {
				dist[nx][ny][land] = dist[x][y][land] + 1;
				bridgeQ.push({ nx,ny,land });
			}
			else {
				cout << dist[x][y][land];
				
                return 0;
			}
		}
	}

	return 0;
}