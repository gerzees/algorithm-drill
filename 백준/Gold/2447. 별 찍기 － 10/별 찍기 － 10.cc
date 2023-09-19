//s 21:49
//e 22:10
#include <bits/stdc++.h>

using namespace std;

char board[6562][6562];

void fillWhiteSpace(int x, int y, int n)
{
	for (int i = x;i < x + n;++i) {

		for (int j = y;j < y + n;++j) {

			board[i][j] = ' ';
		}
	}
}

void drawRecursive(int x, int y, int n)
{
	if (n == 3) {

		for (int i = 0;i < 3;++i) {

			for (int j = 0;j < 3;++j) {

				board[x + i][y + j] = i == 1 && j == 1 ? ' ' : '*';
			}
		}

		return;
	}

	int third = n / 3;

	for (int i = 0;i < 3;++i) {

		for (int j = 0;j < 3;++j) {

			if (i != 1 || j != 1) {
				drawRecursive(x + i * third, y + j * third, third);
			}
			else {
				fillWhiteSpace(x + i * third, y + j * third, third);
			}
		}
	}
}

int main(void)
{
	int n; // n: pow of 3
	cin >> n;
	drawRecursive(0, 0, n);

	for (int i = 0;i < n;++i) {
		cout << board[i] << '\n';
	}

	return 0;
}