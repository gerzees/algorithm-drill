// start 22:30
// end 23:00
#include <bits/stdc++.h>
using namespace std;

char board[101][101];
bool bVisited[101][101];
bool bVisitedW[101][101];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string line;
	for (int i = 0;i < n;++i) {
		cin >> line;
		for (int j = 0;j < n;++j) {
			board[i][j] = line[j];
		}
	}
    
	queue<pair<int, int> > q;
	//queue<pair<int, int> > qw;
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };
	int count = 0;
	int countW = 0;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			if (!bVisited[i][j]) {
				++count;
				q.push({ i,j });
				bVisited[i][j] = true;

				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int k = 0; k < 4; ++k) {
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];

						if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
							continue;
						}

						if (bVisited[nx][ny]) {
							continue;
						}

						if (board[cur.first][cur.second] != board[nx][ny]) {
							continue;
						}

						q.push({ nx,ny });
						bVisited[nx][ny] = true;
					}
				}
			}


			if (!bVisitedW[i][j]) {
				++countW;
				q.push({ i,j });
				bVisitedW[i][j] = true;

				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int k = 0; k < 4; ++k) {
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];

						if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
							continue;
						}

						if (bVisitedW[nx][ny]) {
							continue;
						}

						if (board[cur.first][cur.second] == 'B' && board[nx][ny] != 'B' || board[cur.first][cur.second] != 'B' && board[nx][ny] == 'B') {
							continue;
						}

						q.push({ nx,ny });
						bVisitedW[nx][ny] = true;
					}
				}
			}
		}
	}

	cout << count << ' ' << countW;

	return 0;
}