// s 14:07
// e 15:32
#include <bits/stdc++.h>
using namespace std;

int board[21][21];
int planes[6];
int n;
int m;
int x;
int y;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int rollingIdx[4][4] = { {0,3,2,1},{0,1,2,3},{0,4,2,5}, {0,5,2,4} };

void roll(int dir)
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
		return;
	}

	int topPlane = planes[0];
	
	for (int i = 0;i < 3; ++i) {
		planes[rollingIdx[dir][i]] = planes[rollingIdx[dir][i + 1]];
	}

	planes[rollingIdx[dir][3]] = topPlane;


	if (board[nx][ny] == 0) {
		board[nx][ny] = planes[2];
	}
	else {
		planes[2] = board[nx][ny];
		board[nx][ny] = 0;
	}

	x = nx;
	y = ny;
	cout << planes[0] << '\n';
}

int main(void)
{
	int k;
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	while (k--) {
		int dir;
		cin >> dir;

		roll(dir - 1);
	}

	return 0;
}