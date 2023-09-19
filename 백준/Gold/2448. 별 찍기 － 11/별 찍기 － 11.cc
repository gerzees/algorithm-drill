//s 22:11
//e 23:29
#include <bits/stdc++.h>

using namespace std;

char board[3073][2*3073-1];

void fillCubeBlank(int x, int y, int size)
{
	for (int i = 0;i < size;++i) {
		for (int j = 0;j < size;++j) {
			board[x + i][y + j] = ' ';
		}
	}
}

void fillVerticalLineBlank(int x, int y, int length)
{
	for (int i = 0; i < length;++i) {
		board[x + i][y] = ' ';
	}
}

void drawRecursive(int x, int y, int h)
{
	if (h == 3)
	{
		//x
		for (int i = 0;i < 5;++i) {
			board[x + 0][y + i] = i == 2 ? '*' : ' ';
		}
		//x+1
		for (int i = 0;i < 5;++i) {
			board[x + 1][y + i] = i & 1 ? '*' : ' ';
		}
		//x+2
		for (int i = 0;i < 5;++i) {
			board[x + 2][y + i] = '*';
		}

		return;
	}

	int half = h / 2;
	drawRecursive(x, y + half, half);
	drawRecursive(x + half, y, half);
	drawRecursive(x + half, y + h, half);
	fillCubeBlank(x, y, half);
	fillCubeBlank(x, y + h + half - 1, half);
	fillVerticalLineBlank(x + half, y + h - 1, half);
}

int main(void)
{
	int n;
	cin >> n;
	// h:3, w 5
	drawRecursive(0, 0, n);

	for (int i = 0;i < n;++i) {
		cout << board[i] << '\n';
	}

	return 0;
}