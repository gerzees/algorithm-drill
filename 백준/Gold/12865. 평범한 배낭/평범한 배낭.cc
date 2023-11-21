// 11:02-12:07
// d[i] : 무게 i 이하에서 최대 가치
// d[i] = max(d[i-w[j]]+ v[j], d[i])
//  k >= i >= w[j]
// i 큰 수부터 작은수로.... 작은 수부터 하면 이전 물건으로 갱신한 상태에서 하는게 아니라 이번 물건으로 갱신한 값을 가지고 한 번 더 하는 불상사가 발생
// 초기 조건: d[i] = 0 전부...
#include<bits/stdc++.h>
using namespace std;

int n, k;
int w[100004];
int v[100004];
int d[100004];

int main(void)
{
	cin >> n >> k;

	for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];

	for (int j = 0; j < n; ++j)
		for (int i = k; i >= w[j]; --i)
			d[i] = max(d[i], d[i - w[j]] + v[j]);

	cout << d[k];

	return 0;
}