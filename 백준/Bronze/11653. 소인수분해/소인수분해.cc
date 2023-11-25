//16:49, 16:55해설 읽고 구현
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	if (n == 1) {
		return 0;
	}

	for (int i = 2;i * i <= n;) {
		if (n % i != 0) {
			++i;
			continue;
		}

		cout << i << '\n';
		n /= i;
	}

	cout << n;

	return 0;
}