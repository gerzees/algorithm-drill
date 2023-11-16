//21:15- 21:29
// 테이블 d[i]: i일 전까지 상담을 끝내서 받을 수 있는 최대 이익
// 점화식 d[i]  d[i-1]과 d[i] 중 큰 값으로(이전에 체크한 것 중 최대를 체크하는 바로 앞에 계속 둔다),
// d[i]는 i이전의 어떤 j에서 이익을 누적 갱신한다.
//  j+t[j]-1이 상담 끝나는 날. j+t[j]가 j날 상담 시작해서 얻을 수 있는 이익 받기 시작하는 날이므로
// d[j+t[i]] = 원래 값과 d[j] + p[i]중 큰 값으로 갱신... i=j+t[i]인 i에서 이전 i들로 최대 누적 해둔 것과 직전 인덱스로 최대 이익 가져온 것 중 더 큰 것 즉 최댓값을 가지게 된다.
#include<bits/stdc++.h>
using namespace std;

int t[1500005];
int p[1500005];
int d[1500005];
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> p[i];
	}

	for (int i = 1; i <= n; ++i) {
		d[i] = max(d[i], d[i - 1]);

		if (i + t[i] - 1 <= n) {// 퇴사 전 상담을 마칠 수 있다면
			d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
		}
	}

	cout << max(d[n], d[n + 1]);

	return 0;
}