//15:05-15:23
// d[i]: i번째 추가되는 정삼각형 변의 길이(P(N))
// 점화식: d[i] = d[i-1]+d[i-5] i>5
// 초기조건 d[1..5] = {1,1,1,2,2}
#include<bits/stdc++.h>
using namespace std;

long long d[101];
int main(void)
{
	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	d[4] = 2;
	d[5] = 2;
	d[6] = 3;
	d[7] = 4;
	d[8] = 5;
	for (int i = 9; i <= 100; ++i) {
		d[i] = d[i - 1] + d[i - 5];
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}

	return 0;
}