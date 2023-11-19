// 10:50 11:35
// 테이블: d[s][e] s번째 수부터 e번째 수까지 팰린드롬을 이루면 1, 아니면 0
// 점화식 d[s][e] = (d[s+1][e-1] ==1 && a[s]==a[e])? 1: 0;
// 초기 조건 d[i][i] = 1
#include<bits/stdc++.h>
using namespace std;
int a[2005];
int d[2005][2005];

int isPalindromeRecursive(int s, int e)
{
	if (d[s][e] != -1) {
		return d[s][e];
	}

	if (e - s <= 1) {
		d[s][e] = a[s] == a[e] ? 1 : 0;
		return d[s][e];
	}

	if (a[s] == a[e] && isPalindromeRecursive(s + 1, e - 1)) {
		d[s][e] = 1;
		return d[s][e];
	}

	d[s][e] = 0;
	return d[s][e];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	for (int i = 0;i <= n + 1; ++i) {
		fill(d[i], d[i] + 1 + n, -1);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int s, e;
		cin >> s >> e;
		cout << isPalindromeRecursive(s, e) << '\n';
	}


	return 0;
}