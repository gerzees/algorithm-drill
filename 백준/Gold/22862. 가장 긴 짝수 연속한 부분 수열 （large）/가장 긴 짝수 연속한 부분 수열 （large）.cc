// 답 보고 다시 풀어 본다.
#include<bits/stdc++.h>
using namespace std;

int n;
int k;
int a[1000000];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int en = 0;
	int cnt = a[0] % 2;
	int mxLen = 0;

	for (int st = 0; st < n; ++st) {
		while (en < n - 1 && cnt + a[en + 1] % 2 <= k) {
			++en;
			cnt += a[en] % 2;
		}

		mxLen = max(mxLen, en - st + 1 - cnt);
		cnt -= a[st] % 2;
	}


	cout << mxLen;

	return 0;
}