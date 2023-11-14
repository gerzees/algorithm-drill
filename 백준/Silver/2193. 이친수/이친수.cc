//s 21:34
//e 22:03
//테이블(배열) d[i][0]: 0으로 끝나는 i자리 이친수 개수, d[i][1]: 1로 끝나는 i자리 이친수 개수
// 점화식 d[i][0] = d[i-1][0]+d[i-1][1], d[i][1] = d[i-1][0] 
// 초기 조건 d[1][0]= 0, d[1][1] = 1, d[2][0] = 1, d[2][1]=  0
#include<bits/stdc++.h>
using namespace std;
long long d[92][2];
int main(void)
{
	int n;
	cin >> n;
	d[1][1] = 1;
	for (int i = 2;i <= 90;++i) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}

	cout << d[n][0]+d[n][1];

	return 0;
}