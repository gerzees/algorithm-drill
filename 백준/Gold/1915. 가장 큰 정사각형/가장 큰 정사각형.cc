//10:13-11:48
// 테이블 d[i][j] = a[i][j]를 오를쪽 꼭지점으로 가지는 정사각형의 변의 길이(최대)
// d[0][0]부터 차례로 순회. d[i+1][j+1]의 크기 결정하려면 d[i][j], d[i][j+1], d[i+1][j] 중 하나라도 0이면 누적 못함/ 모두 값이 있으면 d[i][j],d[i][j+1],d[i+1][j]중 최소값+1한다
// 초기 조건: a[i][j]=1 이면 d[i][j]=1
#include<bits/stdc++.h>

int d[1010][1010];
using namespace std;
int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		string line;
		cin >> line;

		for (int j = 0; j < m; ++j) {
			d[i][j] = line[j] - '0';
		}
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!d[i][j] || !d[i][j + 1] || !d[i + 1][j] || !d[i + 1][j + 1]) {
				continue;
			}

			d[i + 1][j + 1] = d[i][j] + 1;
			d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j + 1] + 1);
			d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i + 1][j] + 1);
		}
	}

	int maxSize = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			maxSize = max(maxSize, d[i][j]);
		}
	}

	cout << maxSize * maxSize;

	return 0;
}