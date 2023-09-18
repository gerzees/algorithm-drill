// s 13:17
// e
#include <bits/stdc++.h>
using namespace std;

int paper[130][130];
int cntP[2];

void cutPaperRecursive(int x, int y, int length)
{
	int kind = paper[x][y];
	bool bOnePaper = true;

	for (int i = 0;i < length && bOnePaper;++i) {
		for (int j = 0;j < length;++j) {
			if (kind != paper[x + i][y + j]) {
				bOnePaper = false;
				break;
			}
		}
	}

	if (bOnePaper) {
		++cntP[kind];
		return;
	}

	int half = length / 2;

	cutPaperRecursive(x, y, half);
	cutPaperRecursive(x, y + half, half);
	cutPaperRecursive(x + half, y, half);
	cutPaperRecursive(x + half, y + half, half);
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			cin >> paper[i][j];
		}
	}

	cutPaperRecursive(0, 0, n);
	cout << cntP[0] << '\n' << cntP[1];
	return 0;
}