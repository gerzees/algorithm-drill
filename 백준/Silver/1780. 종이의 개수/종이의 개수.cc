// s 11:46
// e
#include <bits/stdc++.h>
using namespace std;

int paper[2200][2200];
int countP[3];// -1,0,1인 종이의 개수를 각 요소에 저장

void cutPaperRecursive(int x, int y, int n)
{
	int kind = paper[x][y];
	bool bOnePaper = true;

	for (int i = 0;i < n && bOnePaper;++i) {
		for (int j = 0;j < n;++j) {
			if (paper[x + i][y + j] != kind) {
				bOnePaper = false;
				break;
			}
		}
	}

	if (bOnePaper) {
		++countP[kind + 1];
		return;
	}

	int oneThird = n / 3;

	for (int i = 0;i < n;i += oneThird) {
		for (int j = 0;j < n;j += oneThird) {
			cutPaperRecursive(x + i, y + j, oneThird);
		}
	}
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

	for (int c : countP) {
		cout << c << '\n';
	}

	return 0;
}