//8:30, 8:51 이분탐색 설명 읽고 풀었음
#include<bits/stdc++.h>
using namespace std;

int a[100000];
int b[100000];
int bFound[100000];
int main(void)
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	sort(a, a + n);

	for (int i = 0; i < m; ++i) {
		int lbIdx = 0;
		int ubIdx = n;
		while (lbIdx < ubIdx) {
			int checkIdx = (lbIdx + ubIdx) / 2;

			if (a[checkIdx] == b[i]) {
				bFound[i] = 1;
				break;
			}

			if (checkIdx == lbIdx) {// 마지막까지 확인 다했음.
				break;
			}

			if (a[checkIdx] < b[i]) {
				lbIdx = checkIdx;
			}
			else {
				ubIdx = checkIdx;
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << bFound[i] << '\n';
	}

	return 0;
}