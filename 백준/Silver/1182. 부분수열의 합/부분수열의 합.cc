// s 10:46
// e 11:44
#include <bits/stdc++.h>

using namespace std;

int n;
int s;
int cnt;
int sum;
int arr[21]; 

void selectRecursive(int cntSelect, int beginSelect)
{
	if (cntSelect == 0) {

		if (s == sum) {
			++cnt;
		}

		return;
	}

	for (int i = beginSelect; i < n; ++i) {
		sum += arr[i];
		selectRecursive(cntSelect - 1, i + 1);
		sum -= arr[i];
	}
}

int main(void)
{
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for (int i = n; i > 0; --i) {
		selectRecursive(i, 0);
	}

	cout << cnt;
	return 0;
}