// s 21:53
//e 23:23
#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

string board[11];
char e = '.';
char w = '#';
char g = 'O';
char red = 'R';
char blue = 'B';
int n, m;
pair<int, int> R;
pair<int, int> B;
pair<int, int> G;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int minTiltCnt = 12;

bool tilt(int dir, pair<int, int>& b1, pair<int, int>& b2)
{
	bool bDone = false;
	while (true) {
		int nx = b1.X + dx[dir];
		int ny = b1.Y + dy[dir];

		if (board[nx][ny] == w) {
			break;
		}

		b1.X = nx;
		b1.Y = ny;

		if (b1 == G) {
			bDone = true;
			break;
		}
	}

	while (true) {
		int nx = b2.X + dx[dir];
		int ny = b2.Y + dy[dir];

		if (board[nx][ny] == w) {
			break;
		}

		if (nx == b1.X && ny == b1.Y && b1 != G) {
			break;
		}

		b2.X = nx;
		b2.Y = ny;

		if (b2 == G) {
			bDone = true;
			break;
		}
	}

	return bDone;
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == red) {
				R.X = i;
				R.Y = j;
				board[i][j] = e;
			}
			else if (board[i][j] == blue) {
				B.X = i;
				B.Y = j;
				board[i][j] = e;
			}
			else if (board[i][j] == g) {
				G.X = i;
				G.Y = j;
			}
		}
	}


	for (int i = 0; i < (1 << 2 * 10); ++i) {
		pair<int, int> r = R;
		pair<int, int > b = B;
		int packedDir = i;
		bool bDone = false;
		int tiltCnt = 0;
		for (; tiltCnt < 10 && !bDone; ++tiltCnt) {
			int dir = packedDir & 3;
			packedDir >>= 2;
			switch (dir) {
			case 0://right
				bDone = r.Y > b.Y ? tilt(dir, r, b) : tilt(dir, b, r);
				break;
			case 1://down
				bDone = r.X > b.X ? tilt(dir, r, b) : tilt(dir, b, r);
				break;
			case 2://left
				bDone = r.Y < b.Y ? tilt(dir, r, b) : tilt(dir, b, r);
				break;
			case 3://up
				bDone = r.X < b.X ? tilt(dir, r, b) : tilt(dir, b, r);
				break;
			default:
				assert(false);
				break;
			}

		}

		if (!bDone) {
			continue;
		}

		if (b == G) {
			continue;
		}

		if (r == G && tiltCnt < minTiltCnt) {
			if (tiltCnt == 1) {
				cout << 1;
				return 0;
			}

			minTiltCnt = tiltCnt;
		}
	}

	if (minTiltCnt <= 10) {
		cout << minTiltCnt;
	}
	else {
		cout << -1;
	}

	return 0;
}