//14:03, 14:28
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	// nCm n!/(n-m)!*m!
	// 소인수분해 5의 개수가 끝자리 0 개수 결정하는 게 아닌가봄?
	// n 27이라고 하면 5의 배수 개수
	// n/5=5 5,10,15,20,25
	// 25의 배수 개수
	// n/5/5 =1  25
	// factorial에서 5 개수 5+1

	int n, m;
	cin >> n >> m;
	long long primeFactor5Cnt = 0;
	long long primeFactor2Cnt = 0;

	for (int i = n / 5;i != 0; i /= 5) {
		primeFactor5Cnt += i;
	}
	for (int i = (n - m) / 5; i != 0; i /= 5) {
		primeFactor5Cnt -= i;
	}
	for (int i = m / 5; i != 0; i /= 5) {
		primeFactor5Cnt -= i;
	}

	for (int i = n / 2;i != 0; i /= 2) {
		primeFactor2Cnt += i;
	}
	for (int i = (n - m) / 2; i != 0; i /= 2) {
		primeFactor2Cnt -= i;
	}
	for (int i = m / 2; i != 0; i /= 2) {
		primeFactor2Cnt -= i;
	}

	cout << min(primeFactor2Cnt, primeFactor5Cnt);

	return 0;
}