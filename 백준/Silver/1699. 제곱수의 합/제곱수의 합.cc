//11:27- 12:09
// 테이블 d[i] i를 합으로 표현하는 제곱수 항의 최소 개수
// d[i] = d[i-1],d[i-2],d[i-4],d[i-9] .... d[i-제곱수] 중 최소 +1
// d[1] = 1 초기 조건.
// 재귀로
#include<bits/stdc++.h>
using namespace std;

int d[100001];

int getMinCntRecursive(int n)
{
	if (d[n] != -1) {
		return d[n];
	}

	int& minCnt = d[n];
	minCnt = getMinCntRecursive(n - 1) + 1;
	for (int i = 2; n - i * i >= 0; ++i) {
		if (n == i * i) {
			minCnt = 1;
		}
		else {
			minCnt = min(minCnt, getMinCntRecursive(n - i * i) + 1);
		}
	}

	return minCnt;
}
int main(void)
{
	int n;
	cin >> n;
	fill(d, d + 100001, -1);
	d[1] = 1;

	cout << getMinCntRecursive(n);

	return 0;
}