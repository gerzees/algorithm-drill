//s 15:30
//e 15:48
// 배열 점화식 초기조건
// d[i][j] : i번째 집까지 칠했을 때 최솟값(i번째 집을 j색으로 칠했을 때)
// 초기 조건 0번째 집을 각 색으로 칠했을 때 비용
// d[i][j] = min(d[i-1][k],d[i-1][l])+colorCost[i][j]
//  이전까지 최소 비용(칠하고자 하는 색과 다른 2 색 중 더 작은 비용을 가진 걸 택)에 이번 컬러의 값을 더한다
// 마지막 최소값은 n번째까지 최솟값 각 색에 대해 구하고 그 중 최소

#include<bits/stdc++.h>
using namespace std;
int d[1001][3];
int colorCost[1001][3];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> colorCost[i][j];
		}
	}

	d[0][0] = colorCost[0][0];
	d[0][1] = colorCost[0][1];
	d[0][2] = colorCost[0][2];

	for (int i = 1; i < n; ++i) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + colorCost[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + colorCost[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + colorCost[i][2];
	}

	cout << min(min(d[n - 1][0], d[n - 1][1]), d[n - 1][2]);
	return 0;
}