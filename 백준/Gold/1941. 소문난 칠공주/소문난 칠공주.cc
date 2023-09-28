// s 21:49
// e 23:22
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int cnt;
string board[5];
bool bGrouped[5][5];
bool bPushed[5][5];

int cntY;
int cntS;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
pair<int, int> lastMember;

//void printBoard()
//{
//	for (int i = 0; i < 5; ++i) {
//		for (int j = 0; j < 5; ++j) {
//			cout << (bGrouped[i][j] ? board[i][j] : '.');
//		}
//		cout << '\n';
//	}
//}

bool isNeighbor(int x, int y)
{
	for (int i = 0;i < 4;++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx>4 || ny>4) {
			continue;
		}

		if (bGrouped[nx][ny]) {
			return true;
		}
	}

	return false;
}

int getNeighboredCount()
{
	fill(bPushed[0], bPushed[0] + 25, false);
	queue<pair<int, int> > Q;
	bPushed[lastMember.X][lastMember.Y] = true;
	Q.push(lastMember);


	int cnt = 0;
	while (!Q.empty()) {
		pair<int, int>& cur = Q.front();
		Q.pop();
		++cnt;

		for (int i = 0;i < 4;++i) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || ny < 0 || nx>4 || ny>4) {
				continue;
			}

			if (bPushed[nx][ny]) {
				continue;
			}

			if (bGrouped[nx][ny]) {
				bPushed[nx][ny] = true;
				Q.push({ nx,ny });
			}
		}
	}

	return cnt;
}

void makeGroupRecursive(int x, int y)
{
	if (cntY + cntS == 7) {
		if (getNeighboredCount() == 7) {
			++cnt;
			//printBoard();
		}
		return;
	}

	if (y == 5) {
		return;
	}

	{ // 안고르는 경우
		int nx = x + 1;
		int ny = y;

		if (nx == 5) {
			nx = 0;
			ny = y + 1;
		}

		makeGroupRecursive(nx, ny);
	}

	// 고르는 경우
	// group에 들어갈 수 있는 조건
	//  그룹원과 인접(이미 그룹원 존재하면), S가 우위(Y가 3초과 불가)
	char cur = board[x][y];

	//if (cntY + cntS > 0 && !isNeighbor(x, y)) { // 빠지는 경우 발생
	//	return;
	//}

	if (cur == 'Y' && cntY == 3) {
		return;
	}

	{
		int nx = x + 1;
		int ny = y;

		if (nx == 5) {
			nx = 0;
			ny = y + 1;
		}

		if (cur == 'Y') {
			++cntY;
		}
		else {
			++cntS;
		}

		bGrouped[x][y] = true;
		lastMember = { x,y };
		makeGroupRecursive(nx, ny);
		bGrouped[x][y] = false;

		if (cur == 'Y') {
			--cntY;
		}
		else {
			--cntS;
		}
	}
}

int main(void)
{
	for (int i = 0; i < 5; ++i) {
		cin >> board[i];
	}

	makeGroupRecursive(0, 0);

	cout << cnt;

	return 0;
}