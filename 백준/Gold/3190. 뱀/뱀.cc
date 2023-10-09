// s 20:19
// e 21:39
#include<bits/stdc++.h>
using namespace std;
// 0: snake, -1: empty, 1:apple
int board[101][101];
int n;
int k;
int l;
deque<pair<int, int> > Q;
int t;
int dir;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int main(void)
{
	cin >> n >> k;

	for (int i = 0; i < n;++i) {
		fill(board[i], board[i] + n, -1);
	}

	while (k--) {
		int r, c;
		cin >> r >> c;
		board[r - 1][c - 1] = 1;
	}

	Q.push_front({ 0,0 });
	board[0][0] = 0;
	cin >> l;
	bool bEnd = false;
	while (l-- && !bEnd) {
		int x;
		char c;
		cin >> x >> c;

		for (; t < x && !bEnd;++t) {
			auto head = Q.front();
			int nx = head.first + dx[dir];
			int ny = head.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) { // wall
				bEnd = true;
				continue;
			}

			if (board[nx][ny] == 0) { // snake itself
				bEnd = true;
				continue;
			}

			if (board[nx][ny] == -1) {
				auto tail = Q.back();
				Q.pop_back();
				board[tail.first][tail.second] = -1;
			}

			Q.push_front({ nx,ny });
			board[nx][ny] = 0;
		}

		if (c == 'L') {
			--dir;
			dir &= 3;
		}
		else {
			++dir;
			dir &= 3;
		}
	}

	while (!bEnd) {
		++t;
		auto head = Q.front();
		int nx = head.first + dx[dir];
		int ny = head.second + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) { // wall
			bEnd = true;
			continue;
		}

		if (board[nx][ny] == 0) { // snake itself
			bEnd = true;
			continue;
		}

		if (board[nx][ny] == -1) {
			auto tail = Q.back();
			Q.pop_back();
			board[tail.first][tail.second] = -1;
		}

		Q.push_front({ nx,ny });
		board[nx][ny] = 0;
	}

	cout << t;

	return 0;
}