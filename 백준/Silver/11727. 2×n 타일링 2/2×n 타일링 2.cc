//s 10:46
//e 10:53
//테이블(배열)
// d[i] = 2*i 직사각형 타일로 채우는 방법의 수
// d[i] = d[i-1] + 2*d[i-2] i>=3
// d[1] =1, d[2] = 3
#include<bits/stdc++.h>
using namespace std;
int d[1001];
int main(void)
{
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 3;

	for (int i = 3; i <= 1000; ++i) {
		d[i] = (d[i - 1] + 2 * d[i - 2]) % 10007;
	}

	cout << d[n];

	return 0;
}