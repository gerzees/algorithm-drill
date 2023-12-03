// 8:20,8:27
#include<bits/stdc++.h>
using namespace std;
int a[500000];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n);
	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		int target;
		cin >> target;
		cout << binary_search(a, a + n, target) << ' ';
	}

	return 0;
}