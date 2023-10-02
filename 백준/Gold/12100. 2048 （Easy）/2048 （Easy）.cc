//s17:19~17:55, 14:12~
//e 15:11
#include <bits/stdc++.h>
using namespace std;

int N;
int ans;
int board[21][21];
int initialBoard[21][21];
int main(void)
{
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> initialBoard[i][j];
		}
	}

	for (int i = 0; i < 1 << (2 * 5); ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				board[j][k] = initialBoard[j][k];
			}
		}

		int dirSeq = i;
		for (int j = 0; j < 5; ++j) {
			int dir = dirSeq % 4;
			dirSeq /= 4;

			switch (dir) {
			case 0: // R
				for (int k = 0; k < N; ++k) {
					int to = N - 1;
					for (int cur = N - 2; cur >= 0; --cur) {
						if (board[k][cur] == 0) {
							continue;
						}

						if (board[k][to] == board[k][cur])
						{
							board[k][to--] += board[k][cur];
							board[k][cur] = 0;
						}
						else if (board[k][to] == 0) {
							swap(board[k][cur], board[k][to]);
						}
						else {
							swap(board[k][cur], board[k][--to]);
						}
					}
				}

				break;
			case 1:  // U
				for (int k = 0; k < N; ++k) {
					int to = 0;
					for (int cur = 1; cur < N; ++cur) {
						if (board[cur][k] == 0) {
							continue;
						}

						if (board[to][k] == 0) {
							board[to][k] = board[cur][k];
							board[cur][k] = 0;
						}
						else if (board[to][k] == board[cur][k])
						{
							board[to++][k] += board[cur][k];
							board[cur][k] = 0;
						}
						else {
							++to;
							swap(board[cur][k], board[to][k]);
						}
					}
				}
				break;
			case 2:  // L
				for (int k = 0; k < N; ++k) {
					int to = 0;
					for (int cur = 1; cur < N; ++cur) {
						if (board[k][cur] == 0) {
							continue;
						}

						if (board[k][to] == board[k][cur])
						{
							board[k][to++] += board[k][cur];
							board[k][cur] = 0;
						}
						else if (board[k][to] == 0) {
							swap(board[k][cur], board[k][to]);
						}
						else {
							swap(board[k][cur], board[k][++to]);
						}
					}
				}
				break;
			case 3: // D
				for (int k = 0; k < N; ++k) {
					int to = N - 1;
					for (int cur = N - 2; cur >= 0; --cur) {
						if (board[cur][k] == 0) {
							continue;
						}

						if (board[to][k] == 0) {
							board[to][k] = board[cur][k];
							board[cur][k] = 0;
						}
						else if (board[to][k] == board[cur][k])
						{
							board[to--][k] += board[cur][k];
							board[cur][k] = 0;
						}
						else {
							--to;
							swap(board[cur][k], board[to][k]);
						}
					}
				}
				break;
			default:
				assert(false);
				break;
			}
		}

		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (ans < board[j][k]) {
					ans = board[j][k];
				}
			}
		}
	}

	cout << ans;

	return 0;
}