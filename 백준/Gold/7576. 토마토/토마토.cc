// start 8:55
// end 9:53
#include <bits/stdc++.h>

using namespace std;

int boxs[1001][1001];
int days[1001][1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> m >> n;
	int left = n * m; // 안익은 토마토 개수
	int minDays = 0;
	queue<pair<int, int>> Q;

	for (int x = 0; x < n; ++x) {

		for (int y = 0; y < m; ++y) {
			cin >> boxs[x][y];

			if (boxs[x][y] == 0) {
				continue;
			}

			// 익은 토마토 or 토마토 없음
			--left;

			if (boxs[x][y] == 1) {
				Q.push({ x,y });
			}
		}
	}

	while (!Q.empty() && left > 0) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		const int dx[] = { 1,-1,0,0 };
		const int dy[] = { 0,0,1,-1 };
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			if (boxs[nx][ny] != 0 || days[nx][ny] != 0) { // 시작부터 안익은 토마토 아님 or 그후 익었음
				continue;
			}

			Q.push({ nx,ny });
			days[nx][ny] = days[x][y] + 1;

			if (minDays < days[nx][ny]) {
				minDays = days[nx][ny];
			}

			--left;
			if (left == 0) {
				break;
			}
		}
	}

	if (left == 0) {
		cout << minDays;
	}
	else {
		cout << -1;
	}

	return 0;
}