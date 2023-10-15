// s 12:19
// e 14:01
#include<bits/stdc++.h>
using namespace std;

int n;
int nums[1000000];
int tmp[1000000];

void sortRecursive(int beg, int en)
{
	if (beg + 1 == en) {
		return;
	}

	int mid = (beg + en) / 2;
	sortRecursive(beg, mid);
	sortRecursive(mid, en);

	int i1 = beg;
	int i2 = mid;
	for (int i = beg; i < en; ++i) {
		if (i1 == mid) {
			tmp[i] = nums[i2++];
			continue;
		}

		if (i2 == en) {
			tmp[i] = nums[i1++];
			continue;
		}

		tmp[i] = nums[i1] < nums[i2] ? nums[i1++] : nums[i2++];
	}

	for (int i = beg; i < en; ++i) {
		nums[i] = tmp[i];
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	sortRecursive(0, n);

	for (int i = 0; i < n; ++i) {
		cout << nums[i] << '\n';
	}

	return 0;
}