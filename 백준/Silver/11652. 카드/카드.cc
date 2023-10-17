// s 16:53
// e 17:25
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

	long long ans = nums[0];
	int ansCnt = 1;
	int cnt = 1;
	nums[n] = (1ll << 62) + 1;
	for (int i = 1; i < n + 1; ++i) {
		if (nums[i - 1] == nums[i]) {
			++cnt;
		}
		else {
			if (cnt > ansCnt) {
				ans = nums[i - 1];
				ansCnt = cnt;
			}

			cnt = 1;
		}
	}


	cout << ans;

	return 0;
}