// 21:30-21:51
// 테이블 d[i][j]: 길이 i인 계단수 중 j로 끝나는 개수
// 점화식 d[i][j] = d[i-1][j-1]+d[i-1][j+1], j가 0,9인 경우 주의!
// 초기 조건 d[1][0]=0, d[1][1~9] =1
#include<bits/stdc++.h>
using namespace std;
int mod = 1000000000;
int d[101][10];
int main(void)
{
	d[1][0] = 0;
	fill(d[1] + 1, d[1] + 10, 1);

	for (int i = 2;i <= 100;++i) {
		d[i][0] = d[i - 1][1];
		for (int j = 1; j <= 8; ++j) {
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % mod;
		}
		d[i][9] = d[i - 1][8];
	}

	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < 10; ++i) {
		ans = (ans + d[n][i]) % mod;
	}

	cout << ans;

	return 0;
}