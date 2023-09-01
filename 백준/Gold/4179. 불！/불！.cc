// start 10:16 ~10:55 /stop/ re 18:39
// end 
#include <bits/stdc++.h>

using namespace std;

char board[1001][1001];
int fireDist[1001][1001];
int joeDist[1001][1001];
const char WALL = '#';
const char JOE = 'J';
const char FIRE = 'F';
const char AISLE = '.';
const int NOT_YET = -1;
const int IMPOSSIBLE = -2;
queue<pair<int, int> > Q;

int main(void)
{
	int R, C;
	cin >> R >> C;
	pair<int, int> joeStart;

	for (int r = 0; r < R; ++r) {
		string line;
		cin >> line;

		for (int c = 0; c < C; ++c) {
			board[r][c] = line[c];

			switch (board[r][c]) {
			case AISLE:
			{
				fireDist[r][c] = NOT_YET;
				joeDist[r][c] = NOT_YET;
			}
			break;
			case WALL:
			{
				fireDist[r][c] = IMPOSSIBLE;
				joeDist[r][c] = IMPOSSIBLE;
			}
			break;
			case JOE:
			{
				fireDist[r][c] = NOT_YET;
				joeStart.first = r;
				joeStart.second = c;
				joeDist[r][c] = 0;
			}
			break;
			case FIRE:
			{
				Q.push({ r,c });
				fireDist[r][c] = 0;
				joeDist[r][c] = IMPOSSIBLE;
			}
			break;
			default:
				break;
			}
		}
	}

	const int dr[] = { 1,-1,0,0 };
	const int dc[] = { 0,0,1,-1 };

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
				continue;
			}

			if (fireDist[nr][nc] >= 0 || board[nr][nc] == WALL) {
				continue;
			}

			fireDist[nr][nc] = fireDist[r][c] + 1;
			Q.push({ nr,nc });
		}
	}

	Q.push(joeStart);

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		if (r == 0 || r == R - 1 || c == 0 || c == C - 1) {
			cout << joeDist[r][c] + 1;
			return 0;
		}

		for (int i = 0; i < 4; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
				continue;
			}

			if (joeDist[nr][nc] >= 0 || board[nr][nc] == WALL) {
				continue;
			}

			if (fireDist[nr][nc]>=0 && joeDist[r][c] >= fireDist[nr][nc] - 1) {
				joeDist[nr][nc] = IMPOSSIBLE;
				continue;
			}

			joeDist[nr][nc] = joeDist[r][c] + 1;
			Q.push({ nr,nc });
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}