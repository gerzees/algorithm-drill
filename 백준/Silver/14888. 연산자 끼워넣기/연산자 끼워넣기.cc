// s 17:08
// e 17:31
#include <bits/stdc++.h>
using namespace std;

int n;
int operatorCnt[4];
int nums[101];
// 0:+, 1:-, 2:*, 3:/
int operatorPermu[100];
int maxResult = INT_MIN;
int minResult = INT_MAX;
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	for (int i = 0; i < 4; ++i) {
		cin >> operatorCnt[i];
	}

	int permuIdx = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < operatorCnt[i]; ++j) {
			operatorPermu[permuIdx++] = i;
		}
	}

	do {
		int result = nums[0];
		for (int i = 0; i < n - 1; ++i) {
			switch (operatorPermu[i]) {
			case 0:
				result += nums[i + 1];
				break;
			case 1:
				result -= nums[i + 1];
				break;
			case 2:
				result *= nums[i + 1];
				break;
			case 3:
				result /= nums[i + 1];
				break;
			default:
				assert(false);
				break;
			}
		}

		if (result > maxResult) {
			maxResult = result;
		}

		if (result < minResult) {
			minResult = result;
		}

	} while (next_permutation(operatorPermu, operatorPermu + n - 1));

	cout << maxResult << '\n' << minResult;

	return 0;
}