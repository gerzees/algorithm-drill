// s 21:05
// e 22:02
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

char field[6][12];
bool bChecked[6][12];
int ans;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int main(void)
{
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			cin >> field[j][i];
		}
	}

	while (true) {
		bool bChained = false;
		for (int i = 0;i < 6;++i) {
			for (int j = 0;j < 12;++j) {

				if (field[i][j] == '.') {
					continue;
				}

				if (bChecked[i][j]) {
					continue;
				}

				queue<pair<int, int> > checkingQ;
				queue<pair<int, int> > explodingQ;
				checkingQ.push({ i,j });
				bChecked[i][j] = true;
				int connectedCnt = 0;

				while (!checkingQ.empty()) {
					auto& cur = checkingQ.front();
					explodingQ.push(cur);
					checkingQ.pop();
					++connectedCnt;

					for (int k = 0; k < 4; ++k) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];

						if (nx < 0 || nx >= 6 || ny < 0 || ny >= 12) {
							continue;
						}

						if (bChecked[nx][ny]) {
							continue;
						}

						if (field[nx][ny] != field[cur.X][cur.Y]) {
							continue;
						}

						checkingQ.push({ nx,ny });
						bChecked[nx][ny] = true;
					}
				}

				if (connectedCnt < 4) {
					continue;
				}

				bChained = true;
				while (!explodingQ.empty()) {
					auto& target = explodingQ.front();
					explodingQ.pop();

					field[target.X][target.Y] = '.';
				}
			}
		}

		if (!bChained) {
			break;
		}

		++ans;

		// fall puyopuyo & bChecked reset
		for (int i = 0; i < 6; ++i) {
			int to = 11;
			for (int cur = 10; cur >= 0; --cur) {
				if (field[i][cur] == '.') {
					continue;
				}

				if (field[i][to] == '.') {
					field[i][to--] = field[i][cur];
					field[i][cur] = '.';
				}
				else if (cur == to - 1) {
					--to;
				}
				else {
					field[i][--to] = field[i][cur];
					field[i][cur] = '.';
				}
			}
		}

		for (int i = 0; i < 6; ++i) {
			fill(bChecked[i], bChecked[i] + 12, false);
		}
	}

	cout << ans;

	return 0;
}