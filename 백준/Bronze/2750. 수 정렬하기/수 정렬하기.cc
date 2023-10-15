// s 12:13
// e 12:17
#include<bits/stdc++.h>
using namespace std;

int n;
int nums[1000];
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (nums[i] > nums[j]) {
				swap(nums[i], nums[j]);
			}
		}

		cout << nums[i] << '\n';
	}

	

	return 0;
}