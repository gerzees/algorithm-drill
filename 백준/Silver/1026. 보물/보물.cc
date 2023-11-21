// 10:44-11:00
#include<bits/stdc++.h>
using namespace std;

int a[55];
int b[55];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	sort(a, a + n);
	sort(b, b + n);
	int sum = 0;

	for (int i = 0; i < n; ++i) {
		sum += a[i] * b[n - 1 - i];
	}

	cout << sum;
	return 0;
}