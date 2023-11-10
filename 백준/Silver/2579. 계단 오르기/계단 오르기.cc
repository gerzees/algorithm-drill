//s 13:38
//e 15:10
//배열,점화식,초기조건
//d[i]= i번째 계단까지 올라섰을 때 밟지 않을 계단의 합의 최댓값, i번째 계단은 반드시 밟은 계단으로 선택해야함
// 뛰어 넘는 것 최대 1개
// d[1] = step[1], d[2] = step[1]+step[2], d[3] = max(s[1],s[2])+step[3]
// d[4] = max(d[1],d[2])+step[4],
//  d[5] = max(d[2],d[3])+step[5]
//d[i] = max(d[i-2],d[i-3]+step[i-1])+step[i]


#include<bits/stdc++.h>

using namespace std;

int d[301];
int step[301];
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> step[i];
	}

	if (n == 1) {
		cout << step[1];

		return 0;
	}

	if (n == 2) {
		cout << step[1] + step[2];

		return 0;
	}

	if (n == 3) {
		cout << max(step[1], step[2]) + step[3];

		return 0;
	}

	d[1] = step[1];
	d[2] = step[1] + step[2];
	d[3] = max(step[1], step[2]) + step[3];
	for (int i = 4; i <= n; ++i) {
		d[i] = max(d[i - 2], d[i - 3] + step[i - 1]) + step[i];
	}

	cout << d[n];

	return 0;
}