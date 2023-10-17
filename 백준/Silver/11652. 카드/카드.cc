// s 16:53
// e 17:15
#include<bits/stdc++.h>
using namespace std;

long long nums[100001];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	sort(nums, nums + n);

	long long cur = nums[0];
	long long ans = nums[0];
	int ansCnt = 1;
	int curCnt = 1;
	for (int i = 1; i < n; ++i) {
		if (cur == nums[i]) {
			++curCnt;
		}
		else {
			if (curCnt > ansCnt) {
				ans = cur;
				ansCnt = curCnt;
			}

			cur = nums[i];
			curCnt = 1;
		}
	}

	if (curCnt > ansCnt) {
		ans = cur;
		ansCnt = curCnt;
	}

	cout << ans;

	return 0;
}