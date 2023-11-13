//s 10:21
//e 10:41
//테이블(배열): d[i][j]:꼭대기에서 i번째줄, j번째 수까지 오는 최대 경로의 합
//점화식
// d[i][j] = n[i][j] + max(d[i-1][j-1],d[i-1][j])  **d[i-1][j-1]이나, d[i-1][j]가 존재하지 않을 수 있다
//초기조건
// d[0][0] = n[0][0]
#include<bits/stdc++.h>
using namespace std;
int d[501][501];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cin >> d[0][0];
	for (int i = 1;i < n;++i) {
		for (int j = 0;j <= i; ++j) {
			int nij;
			cin >> nij;
			d[i][j] = nij;
			if (j == 0) {
				d[i][j] += d[i - 1][j];
			}
			else {
				d[i][j] += max(d[i - 1][j], d[i - 1][j - 1]);
			}
		}
	}

	cout << *max_element(d[n - 1], d[n - 1] + n);

	return 0;
}