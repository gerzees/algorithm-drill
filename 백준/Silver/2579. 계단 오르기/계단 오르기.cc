//s 13:38
//e
//배열,점화식,초기조건
//int d[301] d[x] x번째 계단에서 얻을 수 있는 최댓값
//d[x] = step[n]+max(d[x-1],d[x-2]) d[x-2]는 무조건 가능함, d[x]가 연속 3번째 계단이면 d[x-1] 불가
//d[1] = step[1],
// d[2] = step[1]+step[2], step[2]
// d[3] = max(step[1]+step[3], step[2]+step[3]),
// d[4] = d[4]+d[3]+d[1], d[4]+d[2]+d[1]
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