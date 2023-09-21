// s 10:46
// e 11:55
#include <bits/stdc++.h>

using namespace std;

int n;
int s;
int arr[21];
int cnt;

void selectRecursive(int index, int total)
{
	if (index == n) {
		if (total == s) {
			++cnt;
		}
		return;
	}

	selectRecursive(index + 1, total); // arr[index] not selected
	selectRecursive(index + 1, total + arr[index]);
}

int main(void)
{
	cin >> n >> s;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	selectRecursive(0, 0);

	if (s == 0) {
		--cnt;
	}

	cout << cnt;

	return 0;
}