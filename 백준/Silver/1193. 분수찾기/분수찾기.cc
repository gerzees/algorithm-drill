//9:14,9:37
#include<bits/stdc++.h>
using namespace std;
//1 2 3 4 ,,, n n+1
// k = n(n+1)/2~(n+1)(n+2)/2 k는 n+1번째 줄 홀수번째 오른쪽으로(분자 큰거 시작) 짝수번째는 왼쪽(분모 큰거 시작)

int main(void)
{
	int x;
	cin >> x;

	if (x == 1) {
		cout << "1/1";
		return 0;
	}
	if (x <= 3) {
		cout << x - 1 << '/' << 4 - x;
		return 0;
	}

	int n = 3;
	for (; n * (n + 1) / 2 < x; ++n) {
	}

	x -= n * (n - 1) / 2;
	if (n % 2) {
		cout << n + 1 - x << '/' << x;
	}
	else {
		cout << x << '/' << n + 1 - x;
	}

	return 0;
}