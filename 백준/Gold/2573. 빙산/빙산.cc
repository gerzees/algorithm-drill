// s 11:33
// e 12:49
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[301][301];
int dist[301][301];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main(void)
{
	int N, M;
	cin >> N >> M;
	queue<pair<int, int> > seaQ;
	queue<pair<int, int> > iceQ;
	list<pair<int, int> > iceburgL;

	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			cin >> board[i][j];

			if (board[i][j] != 0) {
				iceburgL.push_back({ i,j });
			}
		}
	}

	for (int distCount = 0;!iceburgL.empty(); ++distCount) {

		for (list<pair<int, int> >::iterator it = iceburgL.begin();it != iceburgL.end();++it) {
			pair<int, int>& ice = *it;

			for (int i = 0;i < 4;++i) {
				int nx = ice.X + dx[i];
				int ny = ice.Y + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
					continue;
				}

				if (board[nx][ny] > 0) {
					continue;
				}

				if (dist[nx][ny] > distCount) {
					continue;
				}

				seaQ.push({ nx,ny });
				dist[nx][ny] = distCount + 1;
			}
		}



		while (!seaQ.empty()) {
			pair<int, int>& cur = seaQ.front();
			seaQ.pop();

			for (int i = 0;i < 4;++i) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
					continue;
				}

				if (board[nx][ny] == 0) {
					continue;
				}

				--board[nx][ny];
			}
		}

		for (list<pair<int, int> >::iterator it = iceburgL.begin();it != iceburgL.end();) {
			pair<int, int>& ice = *it;

			if (board[ice.X][ice.Y] == 0) {
				it = iceburgL.erase(it);
			}
			else {
				++it;
			}
		}

		iceQ.push(iceburgL.front());
		dist[iceburgL.front().X][iceburgL.front().Y] = distCount + 1;
		int aPieceSize = 1;

		while (!iceQ.empty()) {
			pair<int, int>& cur = iceQ.front();
			iceQ.pop();

			for (int i = 0;i < 4;++i) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
					continue;
				}

				if (board[nx][ny] == 0) {
					continue;
				}

				if (dist[nx][ny] > distCount) {
					continue;
				}

				iceQ.push({ nx,ny });
				dist[nx][ny] = distCount + 1;
				++aPieceSize;
			}
		}

		if (aPieceSize < iceburgL.size()) {
			cout << distCount + 1;
			return 0;
		}
	}

	cout << 0;
	
    return 0;
}