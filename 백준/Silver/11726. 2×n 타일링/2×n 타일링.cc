//s 12:50
//e 13:10
// 테이블(배열), 점화식, 초기조건
// d[i] 2*i직사각형 채우는 방법의 수
// d[i]은 d[i-1]에 2*1한 개 채우는 방법이랑 d[i-2]에 1*2두 개 채우는 방법
// d[i] = d[i-1]+d[i-2]
// d[1] = 1, d[2] =2
#include<bits/stdc++.h>
using namespace std;
int d[1005];
int main(void)
{
	int n;
	cin >> n;

	d[1] = 1;
	d[2] = 2;

	if (n <= 2) {
		cout << d[n];

		return 0;
	}

	for (int i = 3; i <= n; ++i) {
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}

	cout << d[n];

	return 0;

}