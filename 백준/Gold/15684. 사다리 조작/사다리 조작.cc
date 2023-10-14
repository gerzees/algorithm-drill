// s 14:39
// e 14:43
#include<bits/stdc++.h>
using namespace std;

bool board[11][31];
int n, m, h;
int ans = INT_MAX;

void selectLadderRecursive(int x, int y, int cnt)
{
	if (x == n || cnt >= 3) {// 선택 끝(고를 게 더 없거나 3개 다 고름)..  검사해야함
		bool bSuccess = true;
		for (int i = 1; i <= n && bSuccess; ++i) {
			int curLine = i;
			for (int j = 1; j <= h; ++j) {
				if (board[curLine][j] == 0 && board[curLine - 1][j] == 0) {
					continue;
				}

				if (board[curLine][j]) {
					++curLine;
				}
				else {
					--curLine;
				}
			}

			if (curLine != i) {
				bSuccess = false;
				break;
			}
		}

		if (bSuccess && cnt < ans) {
			ans = cnt;
		}

		return;
	}

	int ny = y + 1;
	int nx = x;

	if (y == h) {
		ny = 0;
		++nx;
	}

	// 안고르고 넘김
	selectLadderRecursive(nx, ny, cnt);


	// 고르고 넘김
	// 사다리 있으면 안고르고 넘길 수 밖에..
	if (board[x][y] || board[x - 1][y] || board[x + 1][y]) {//사다리 원래 있던 자리거나, 좌우에 있으면 못 고른다.
		return;
	}

	board[x][y] = 1;
	selectLadderRecursive(nx, ny, cnt + 1);
	board[x][y] = 0;// 끝나면 원상복구
}

int main(void)
{
	cin >> n >> m >> h;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		board[b][a] = 1;
	}

	selectLadderRecursive(1, 1, 0);

	if (ans > 3) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}