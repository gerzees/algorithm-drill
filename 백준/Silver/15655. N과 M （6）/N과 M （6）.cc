//s 14:24
//e 14:47
#include <bits/stdc++.h>

using namespace std;

int N, M;
int num[8];
int arr[8];

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}

	sort(num, num + N);

	for (int i = 0; i < N; ++i) {
		arr[i] = i < M ? 0 : 1;
	}

	do {
		
		for (int i = 0; i < N; ++i) {
			if (arr[i] == 0) {
				cout << num[i] << ' ';
			}
		}
		cout << '\n';

	} while (next_permutation(arr, arr + N));

	return 0;
}