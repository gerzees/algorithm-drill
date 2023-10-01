// s14:08
// e15:13
#include <bits/stdc++.h>
using namespace std;

int room[9][9];
tuple<int, int, int> cctv[9];
int cctvCnt;
int notCoverdCnt;
int ans;
int n, m;

void checkPositiveXDirection(int x, int y)
{
	for (int i = x + 1; i < n; ++i) {
		if (room[i][y] == 6) {
			break;
		}

		if (room[i][y] > 0) {
			continue;
		}

		if (room[i][y] == 0) {
			--notCoverdCnt;
		}

		--room[i][y];
	}
}

void checkNegativeXDirection(int x, int y)
{
	for (int i = x - 1; i >= 0; --i) {
		if (room[i][y] == 6) {
			break;
		}

		if (room[i][y] > 0) {
			continue;
		}

		if (room[i][y] == 0) {
			--notCoverdCnt;
		}

		--room[i][y];
	}
}

void checkPositiveYDirection(int x, int y)
{
	for (int i = y + 1; i < m; ++i) {
		if (room[x][i] == 6) {
			break;
		}

		if (room[x][i] > 0) {
			continue;
		}

		if (room[x][i] == 0) {
			--notCoverdCnt;
		}

		--room[x][i];
	}
}

void checkNegativeYDirection(int x, int y)
{
	for (int i = y - 1; i >= 0; --i) {
		if (room[x][i] == 6) {
			break;
		}

		if (room[x][i] > 0) {
			continue;
		}

		if (room[x][i] == 0) {
			--notCoverdCnt;
		}

		--room[x][i];
	}
}

void uncheckPositiveXDirection(int x, int y)
{
	for (int i = x + 1; i < n; ++i) {
		if (room[i][y] == 6) {
			break;
		}

		if (room[i][y] > 0) {
			continue;
		}

		if (room[i][y] == -1) {
			++notCoverdCnt;
		}

		++room[i][y];
	}
}

void uncheckNegativeXDirection(int x, int y)
{
	for (int i = x - 1; i >= 0; --i) {
		if (room[i][y] == 6) {
			break;
		}

		if (room[i][y] > 0) {
			continue;
		}

		if (room[i][y] == -1) {
			++notCoverdCnt;
		}

		++room[i][y];
	}
}

void uncheckPositiveYDirection(int x, int y)
{
	for (int i = y + 1; i < m; ++i) {
		if (room[x][i] == 6) {
			break;
		}

		if (room[x][i] > 0) {
			continue;
		}

		if (room[x][i] == -1) {
			++notCoverdCnt;
		}

		++room[x][i];
	}
}

void uncheckNegativeYDirection(int x, int y)
{
	for (int i = y - 1; i >= 0; --i) {
		if (room[x][i] == 6) {
			break;
		}

		if (room[x][i] > 0) {
			continue;
		}

		if (room[x][i] == -1) {
			++notCoverdCnt;
		}

		++room[x][i];
	}
}

void setCCTVRecursive(int index)
{
	if (index == cctvCnt) {

		if (ans > notCoverdCnt) {
			ans = notCoverdCnt;
		}
		return;
	}

	int x, y, kind;
	tie(x, y, kind) = cctv[index];

	switch (kind) {
	case 1:
		// -x direction
		checkNegativeXDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckNegativeXDirection(x, y);

		// +x direction
		checkPositiveXDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckPositiveXDirection(x, y);

		// -y direction
		checkNegativeYDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckNegativeYDirection(x, y);

		// +y direction
		checkPositiveYDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckPositiveYDirection(x, y);

		break;

	case 2:
		// +-x direction
		checkNegativeXDirection(x, y);
		checkPositiveXDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckNegativeXDirection(x, y);
		uncheckPositiveXDirection(x, y);

		//+-y direction
		checkNegativeYDirection(x, y);
		checkPositiveYDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckNegativeYDirection(x, y);
		uncheckPositiveYDirection(x, y);
		break;

	case 3:
		// +x,+y
		checkPositiveXDirection(x, y);
		checkPositiveYDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckPositiveXDirection(x, y);
		uncheckPositiveYDirection(x, y);

		// -x,+y
		checkNegativeXDirection(x, y);
		checkPositiveYDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckNegativeXDirection(x, y);
		uncheckPositiveYDirection(x, y);

		// -x, -y
		checkNegativeXDirection(x, y);
		checkNegativeYDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckNegativeXDirection(x, y);
		uncheckNegativeYDirection(x, y);

		// +x,-y
		checkPositiveXDirection(x, y);
		checkNegativeYDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckPositiveXDirection(x, y);
		uncheckNegativeYDirection(x, y);
		break;

	case 4:
		//-x
		checkPositiveXDirection(x, y);
		checkNegativeYDirection(x, y);
		checkPositiveYDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckPositiveXDirection(x, y);
		uncheckNegativeYDirection(x, y);
		uncheckPositiveYDirection(x, y);

		//+x
		checkNegativeXDirection(x, y);
		checkNegativeYDirection(x, y);
		checkPositiveYDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckNegativeXDirection(x, y);
		uncheckNegativeYDirection(x, y);
		uncheckPositiveYDirection(x, y);

		//-y
		checkNegativeXDirection(x, y);
		checkPositiveXDirection(x, y);
		checkPositiveYDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckNegativeXDirection(x, y);
		uncheckPositiveXDirection(x, y);
		uncheckPositiveYDirection(x, y);

		//+y
		checkNegativeXDirection(x, y);
		checkPositiveXDirection(x, y);
		checkNegativeYDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckNegativeXDirection(x, y);
		uncheckPositiveXDirection(x, y);
		uncheckNegativeYDirection(x, y);
		break;

	case 5:
		// all direction
		checkNegativeXDirection(x, y);
		checkPositiveXDirection(x, y);
		checkNegativeYDirection(x, y);
		checkPositiveYDirection(x, y);
		setCCTVRecursive(index + 1);
		uncheckNegativeXDirection(x, y);
		uncheckPositiveXDirection(x, y);
		uncheckNegativeYDirection(x, y);
		uncheckPositiveYDirection(x, y);
		break;

	default:
		assert(false);
		break;
	}
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> room[i][j];

			if (room[i][j] == 0) {
				++notCoverdCnt;
			}
			else if (room[i][j] < 6) {
				cctv[cctvCnt++] = { i,j,room[i][j] };
			}
		}
	}

	ans = notCoverdCnt;
	setCCTVRecursive(0);
	cout << ans;

	return 0;
}