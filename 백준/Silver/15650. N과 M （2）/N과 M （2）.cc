// s 12:57
// e 13:23
#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int arr[8];

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		arr[i] = i < m ? 0 : 1;
	}

	do {
		for (int i = 0; i < n; ++i) {
			if (arr[i] == 0) {
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';

	} while (next_permutation(arr, arr + n));

	return 0;
}