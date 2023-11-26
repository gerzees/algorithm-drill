// 12:04,12:11+15:33,15:45
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<bool> bDeleted(1010, false);
	int n, k;
	cin >> n >> k;
	int delCnt = 0;
	for (int i = 2;i <= n;++i) {
		if (bDeleted[i]) {
			continue;
		}

		for (int j = i; j <= n; j += i) {
			if (bDeleted[j]) {
				continue;
			}

			bDeleted[j] = true;
			++delCnt;
			if (delCnt == k) {
				cout << j;
				return 0;
			}
		}
	}

	return 0;
}