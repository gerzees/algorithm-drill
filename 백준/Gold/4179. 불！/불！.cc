// start 10:06
// end 10:51
// 어제 4시간 넘게 잡고 있었는데 못 품. 풀이 보고 겨우 이해.
// 불이 고립된 경우를 생각 못했음. 
// J의 BFS에서 불에 잡히는거 검사할 때, 불이 번진 곳인지 확인해야함(distF[nr][nc]>=0)
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	char board[1001][1001];
	int R, C;
	int distF[1001][1001] = { 0, };
	int distJ[1001][1001] = { 0, };
	queue<pair<int, int> > Q;
	pair<int, int> JStart;

	cin >> R >> C;
	for (int r = 0; r < R; ++r) {
		string line;
		cin >> line;

		for (int c = 0; c < C; ++c) {
			board[r][c] = line[c];

			switch (board[r][c]) {
			case '#':
				break;
			case '.':
			{
				distF[r][c] = -1;
				distJ[r][c] = -1;
			}
			break;
			case 'F':
				Q.push({ r,c });
				break;
			case 'J':
			{
				distF[r][c] = -1;

				if (r == 0 || c == 0 || r == R - 1 || c == C - 1) {
					cout << 1;
					return 0;
				}

				JStart.first = r;
				JStart.second = c;
			}
			break;
			}
		}
	}

	const int dr[] = { 1,-1,0,0 };
	const int dc[] = { 0,0,1,-1 };

	while (!Q.empty()) { // Fire BFS
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
				continue;
			}

			if (board[nr][nc] == '#' || distF[nr][nc] >= 0) {
				continue;
			}

			distF[nr][nc] = distF[r][c] + 1;
			Q.push({ nr,nc });
		}
	}


	Q.push(JStart);

	while (!Q.empty()) { // J BFS
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();


		for (int i = 0; i < 4; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (board[nr][nc] == '#' || distJ[nr][nc] >= 0) {
				continue;
			}

			if (distF[nr][nc] >= 0 && distF[nr][nc] <= distJ[r][c] + 1) {
				continue;
			}

			if (nr == 0 || nr == R - 1 || nc == 0 || nc == C - 1) {
				cout << distJ[r][c] + 2;
				return 0;
			}

			distJ[nr][nc] = distJ[r][c] + 1;
			Q.push({ nr,nc });
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}