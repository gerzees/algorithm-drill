// s 15:52
// e 16:59
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int board[9][9];
int caseBoard[9][9];
int n, m;
int selected[82];
vector<pair<int, int>> virus;
int startSafeArea = -3;
int maxSafeArea;

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (board[i][j] == 0) {
				++startSafeArea;
			}
		}
	}

	for (int i = n * m - 3; i < n * m; ++i) {
		selected[i] = 1;
	}

	do {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m;++j) {
				caseBoard[i][j] = board[i][j];
			}
		}

		bool bWrongCase = false;
		for (int i = 0; i < n * m; ++i) {
			if (selected[i] == 1) {
				int x = i / m;
				int y = i % m;

				if (caseBoard[x][y] != 0) {
					bWrongCase = true;
					break;
				}
				caseBoard[x][y] = 1;
			}
		}

		if (bWrongCase) {
			continue;
		}

		// 바이러스 퍼트리기
		int safeArea = startSafeArea;
		queue<pair<int, int>> Q;
		for (auto v : virus) {
			Q.push(v);
		}

		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();

			for (int i = 0; i < 4; ++i) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}

				if (caseBoard[nx][ny] != 0) {
					continue;
				}

				Q.push({ nx,ny });
				caseBoard[nx][ny] = 2;
				--safeArea;
			}
		}

		if (maxSafeArea < safeArea) {
			maxSafeArea = safeArea;
		}
	} while (next_permutation(selected, selected + n * m));

	cout << maxSafeArea;

	return 0;
}