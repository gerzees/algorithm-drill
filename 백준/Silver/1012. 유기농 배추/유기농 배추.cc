// 14:13
// 15:00
#include <bits/stdc++.h>
using namespace std;
int board[51][51];
int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		int M; // 가로
		int N; // 세로
		int K; // 배추 개수
		cin >> M >> N >> K;
		queue<pair<int, int> > qAllB;
		while (K--) {
			int x, y;
			cin >> x >> y;
			qAllB.push({ x,y });
			board[x][y] = -1;
		}


		int count = 0;

		while (!qAllB.empty()) {

			int x = qAllB.front().first;
			int y = qAllB.front().second;
			qAllB.pop();

			if (board[x][y] == 0) {
				continue;
			}

			++count;

			queue<pair<int, int> > qB;
			qB.push({ x,y });
			board[x][y] = 0;


			while (qB.size()>0)
			{
				pair<int,int> cur = qB.front();
				qB.pop();
				const int dx[] = { 1,-1,0,0 };
				const int dy[] = { 0,0,-1,1 };

				for (int i = 0;i < 4;++i) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];

					if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
						continue;
					}

					if (board[nx][ny] == 0) {
						continue;
					}

					qB.push({ nx,ny });
					board[nx][ny] = 0;
				}
			}
		}

		cout << count << '\n';
	}

	return 0;
}