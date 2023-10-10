// s 21:07
// e 21:50
#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int board[501][501];
pair<int, int> tetro1[2][4] = { {{0,0},{0,1},{0,2},{0,3}},{{0,0},{1,0},{2,0},{3,0}} };
pair<int, int> tetro2[1][4] = { {{0,0}, {0,1},{1,0},{1,1}} };
pair<int, int> tetro3[8][4] = { {{0,0},{1,0},{2,0},{2,1}},{{1,0},{1,1},{1,2},{0,2}},{{0,0},{1,0},{0,1},{0,2}},{{0,0},{0,1},{1,1},{2,1}},{{0,1},{1,1},{2,1},{2,0}},{{0,0},{0,1},{0,2},{1,2}},{{0,0},{0,1},{1,0},{2,0}},{{0,0},{1,0},{1,1},{1,2}} };
pair<int, int> tetro4[4][4] = { { {0,0}, {1,0}, {1,1}, {2,1}},{ {1,0}, {1,1}, {0,1}, {0,2}},{ {0,1}, {1,1}, {1,0}, {2,0}},{ {0,0}, {0,1}, {1,1}, {1,2}} };
pair<int, int> tetro5[4][4] = { {{0,0},{0,1},{0,2},{1,1}},{{0,0},{1,0},{2,0},{1,1}},{{1,0},{1,1},{1,2},{0,1}},{{0,1},{1,1},{2,1},{1,0}} };

pair<int, int>(*tetros[5])[4] = { tetro1,tetro2,tetro3,tetro4,tetro5 };
int cnts[5] = { 2,1,8,4,4 };
int maxSum;
int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			for (int i = 0; i < 5; ++i) {
				for (int j = 0;j < cnts[i];++j) {
					int sum = 0;
					bool bOutOfBoard = false;
					for (int k = 0; k < 4; ++k) {
						int nx = x + tetros[i][j][k].first;
						int ny = y + tetros[i][j][k].second;

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
							bOutOfBoard = true;
							break;
						}

						sum += board[nx][ny];
					}

					if (!bOutOfBoard && sum > maxSum) {
						maxSum = sum;
					}
				}
			}
		}
	}

	cout << maxSum;

	return 0;
}