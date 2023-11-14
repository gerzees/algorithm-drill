//s 22:04
//e 못 풀어서 해답 봤음
// 테이블 d[i] i번째까지 수 중에서 i번째 포함하는 연속합 최대
// d[i] = d[i-1]과 i번째의 합과 i번째 중 큰 거, 즉 이전 연속합 최대가 득이면 연속해서 합하고 아니면 새로 시작
// d[1]=1번째 수
// d[i]중에 최대 고르면 최대 연속합 구할 수 있다
#include<bits/stdc++.h>
using namespace std;
int d[100001];
int sumMax = INT32_MIN;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cin >> d[1];

	for (int i = 2; i <= n; ++i) {
		int num;
		cin >> num;
		d[i] = max(d[i - 1] + num, num);
	}

	cout << *max_element(d + 1, d + 1 + n);

	return 0;
}