// start 9:08
// end 9:58
#include <bits/stdc++.h>
using namespace std;

int space[101][101][101];
int main(void)
{
	int m, n, h;// 가로,세로,높이
	cin >> m >> n >> h;
	queue<tuple<int, int, int> > q;
	int countGreen = 0;
	// n개 줄, 각 줄 m개 정수, h번 반복
	for (int k = 0;k < h;++k) {
		for (int i = 0;i < n;++i) {
			for (int j = 0;j < m;++j) {
				int tomato;
				cin >> tomato;
				space[i][j][k] = tomato;
				if (tomato == 1) {
					q.push({ i,j,k });
				}
				else if (tomato == 0) {
					++countGreen;
				}
			}
		}
	}

	int day = 0;

	while (!q.empty() && countGreen > 0) {
		++day;
		int count = q.size();
		//cout << "day: " << day << '\n';
		while (count--) {
			tuple<int, int, int> cur = q.front();
			q.pop();
			//cout << get<0>(cur) << ' ' << get<1>(cur) << ' ' << get<2>(cur) << '\n';
			const int dx[] = { 1,-1,0,0, 0,0 };
			const int dy[] = { 0,0,1,-1, 0,0 };
			const int dz[] = { 0,0,0,0, 1,-1 };
			for (int i = 0;i < 6;++i) {
				int nx = get<0>(cur) + dx[i];
				int ny = get<1>(cur) + dy[i];
				int nz = get<2>(cur) + dz[i];

				if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) {
					continue;
				}

				if (space[nx][ny][nz] != 0) {
					continue;
				}

				q.push({ nx,ny,nz });
				space[nx][ny][nz] = 1;
				--countGreen;
			}
		}
	}

	if (countGreen > 0) {
		cout << -1;

		return 0;
	}

	cout << day;

	return 0;
}