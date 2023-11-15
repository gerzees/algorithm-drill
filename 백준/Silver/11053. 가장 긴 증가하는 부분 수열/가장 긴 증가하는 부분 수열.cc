//14:50-
//테이블 d[i]: i번째 수를 포함하는 증가하는 부분 수열 길이
//초기 조건 d[1] = 1
//점화식 d[i]= a[i]>a[j]인 j중 가장 큰 d[j]+1
#include<bits/stdc++.h>
using namespace std;
int d[1001];
int a[1001];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	d[1] = 1;

	for (int i = 2; i <= n; ++i) {
		d[i] = 1;
		for (int j = 1; j < i; ++j) {
			if (a[i] > a[j]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	cout << *max_element(d + 1, d + 1 + n);

	return 0;
}