// s 14:14
// e 14:23
#include <bits/stdc++.h>

using namespace std;

int N, M;
int numbers[8];
bool bUsed[8];
int arr[8];

void selectRecursive(int index)
{
	if (index == M) {

		for (int i = 0; i < M; ++i) {
			cout << arr[i] << ' ';
		}

		cout << '\n';

		return;
	}

	for (int i = 0; i < N; ++i) {
		if (bUsed[i]) {
			continue;
		}

		arr[index] = numbers[i];
		bUsed[i] = true;
		selectRecursive(index + 1);
		bUsed[i] = false;
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> numbers[i];
	}

	sort(numbers, numbers + N);

	selectRecursive(0);

	return 0;
}