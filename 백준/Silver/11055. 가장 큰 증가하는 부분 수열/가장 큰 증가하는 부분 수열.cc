//10:35-11:33
// 테이블 d[i] i번째 원소 포함하는 부분 수열 중 합이 가장 큰 것
// 점화식 d[i]  = a[i]>a[k]인 k중 d[k]가 가장 큰 값에 a[i]더함, 만약에 a[i]>a[k]없으면 d[i] = a[i]
// 초기조건 d[1] = a[1]
#include<bits/stdc++.h>
using namespace std;
int d[1001];
int a[1001];
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> a[i];
	}

	d[1] = a[1];

	for (int i = 2;i <= n; ++i) {
		d[i] = a[i];
		int maxPartSum = 0;

		for (int k = 1;k <= i - 1;++k) {
			if (a[i] > a[k] && maxPartSum < d[k]) {
				maxPartSum = d[k];
			}
		}

		d[i] += maxPartSum;
	}

	cout << *max_element(d + 1, d + 1001);

	return 0;
}