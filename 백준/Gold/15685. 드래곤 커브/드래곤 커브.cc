// s 21:06
// e 21:58
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[101][101];
vector<pair<int, int>> dragons[4];
int main(void)
{
	int n;
	cin >> n;

	// gen 0
	dragons[0].push_back({ 0,0 });
	dragons[0].push_back({ 0,1 });
	for (int i = 0; i < 10;++i) {
		int prevEnd = dragons[0].size() - 1;
		pair<int, int> mid = dragons[0][prevEnd];
		pair<int, int> translation = { -mid.Y, mid.X };
		for (int j = prevEnd - 1; j >= 0; --j) {
			pair<int, int> added = { dragons[0][j].Y,-dragons[0][j].X };
			dragons[0].push_back({ mid.X + added.X + translation.X,mid.Y + added.Y + translation.Y });
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (auto p : dragons[i]) {
			dragons[i + 1].push_back({ -p.Y,p.X });
		}
	}

	for (int i = 0; i < n; ++i) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		for (int j = 0; j < (1 << g) + 1;++j) {
			board[x + dragons[d][j].X][y + dragons[d][j].Y] = 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) {
				++ans;
			}
		}
	}

	cout << ans;

	return 0;
}