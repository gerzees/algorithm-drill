// s 13:29
// e 14:20
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

enum ESymbol {
	Empty = '.',
	Wall = '#',
	Start = '@',
	Fire = '*'
};

int distH[1001][1001]; // Human
int distF[1001][1001]; // Fire
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
vector<int> ans;

int main(void)
{
	int countCase;
	cin >> countCase;

	while (countCase--) {
		queue<pair<int, int> > qH;
		queue<pair<int, int> > qF;
		int w;
		int h;
		bool bEscape = false;
		cin >> w >> h;

		for (int i = 0;i < h;++i) {
			string line;
			cin >> line;
			fill(distH[i], distH[i] + w, -1);
			fill(distF[i], distF[i] + w, -1);

			for (int j = 0;j < w;++j) {

				switch (line[j]) {

				case Empty:
					break;

				case Wall:
					distH[i][j] = 0;
					distF[i][j] = 0;
					break;

				case Start:
					qH.push({ i,j });
					distH[i][j] = 0;
					break;

				case Fire:
					qF.push({ i,j });
					distF[i][j] = 0;
					//distH[i][j] = 0;
					break;

				default:
					assert(false);
					break;
				}
			}
		}

		while (!bEscape && qH.size() > 0) {
			int countF = qF.size();
			int countH = qH.size();

			while (countF--) {
				pair<int, int> cur = qF.front();
				qF.pop();

				for (int i = 0;i < 4;++i) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];

					if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
						continue;
					}

					if (distF[nx][ny] != -1) {
						continue;
					}

					qF.push({ nx,ny });
					distF[nx][ny] = distF[cur.X][cur.Y] + 1;
				}
			}

			while (countH-- && !bEscape) {
				pair<int, int> cur = qH.front();
				qH.pop();
				
				if (cur.X == 0 || cur.X == h - 1 || cur.Y == 0 || cur.Y == w - 1) {
					ans.push_back(distH[cur.X][cur.Y] + 1);
					bEscape = true;
					break;
				}

				for (int i = 0;i < 4; ++i) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];

					if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
						continue;
					}

					if (distH[nx][ny] != -1) {
						continue;
					}

					if (distF[nx][ny] != -1) {
						continue;
					}

					qH.push({ nx,ny });
					distH[nx][ny] = distH[cur.X][cur.Y] + 1;
				}
			}
		}

		if (!bEscape) {
			ans.push_back(-1);
		}
	}

	for (int dist : ans) {
		if (dist == -1) {
			cout << "IMPOSSIBLE";
		}
		else {
			cout << dist;
		}

		cout << '\n';
	}

	return 0;
}