//s 13:38
//e 14:13
//배열,점화식,초기조건
//int d1[301] d1[x] 직전 계단 밟은 경우 x번째 계단에서 얻을 수 있는 최댓값(전전 계단은 밟을 수 없다)
//int d2[301] d2[x] 직전 계단 안밟은 경우 x번째 계단에서 얻을 수 있는 최댓값(전전 계단은 밟아야만 한다)
// 직전에 안 밟은거 최대값d2, 직전에 밟은 거 최대값d1
//d1[1] = step[1], d2[1] = step[1]
//d1[2] = step[2]+step[1], d2[2] = step[2]
//d1[3] = step[3]+d2[2], d2[3] = step[3]+max(d1[1],d2[1])
//d1[4] = step[4]+d2[3], d2[4] = step[4]+max(d1[2],d2[2])


#include<bits/stdc++.h>

using namespace std;

int d1[301];
int d2[301];
int steps[301];
int main(void)
{
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; ++i) {
		cin >> steps[i];
	}

	d1[1] = d2[1] = steps[1];
	d1[2] = d2[1] + steps[2];
	d2[2] = 0 + steps[2];
	for (int i = 3; i <= cnt;++i) {
		d1[i] = d2[i - 1] + steps[i];
		d2[i] = max(d1[i - 2], d2[i - 2]) + steps[i];
	}

	cout << max(d1[cnt], d2[cnt]);

	return 0;
}