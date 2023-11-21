// 10:25-10:40
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0;i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n);
	int maxWeight = 0;

	for (int i = 0; i < n; ++i) {
		int ropeCnt = n - i;
		int minWeight = a[i];
		int weight = ropeCnt * minWeight;
		maxWeight = max(maxWeight, weight);
	}

	cout << maxWeight;
	return 0;
}