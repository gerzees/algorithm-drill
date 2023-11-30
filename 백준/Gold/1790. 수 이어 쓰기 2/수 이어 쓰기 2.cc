// 9:01,10:19
// 1~ 9 한자리 총 길이 9
// 10~99 두자리 총 길이 2* 90
// 100~999 세자리 총 길이 3* 900
#include<bits/stdc++.h>
using namespace std;
int main(void) {
	int n, k;
	cin >> n >> k;

	int nCnt = 9;
	int nLen = 1;
	int totLen = 0;

	while (nCnt < n) {
		totLen += nCnt * nLen;
		n -= nCnt;
		nCnt *= 10;
		++nLen;
	}
	totLen += n * nLen;

	if (k > totLen) {
		cout << -1;

		return 0;
	}

	n = 0;
	nCnt = 9;
	nLen = 1;
	totLen = 0;
	//최대값일 때 오버플로우 발생가능 nCnt=9, nLen=9억 ->81억
	while ((long long)nCnt * nLen <= k) {
		k -= nCnt * nLen;
		n += nCnt;
		nCnt *= 10;
		++nLen;
	}

	while (nLen <= k) {
		k -= nLen;
		++n;
	}

	if (k == 0) {
		cout << n % 10;
	}
	else {
		++n;
		vector<int> a;

		while (n) {
			a.push_back(n % 10);
			n /= 10;
		}

		cout << a[a.size() - k];
	}

	return 0;
}