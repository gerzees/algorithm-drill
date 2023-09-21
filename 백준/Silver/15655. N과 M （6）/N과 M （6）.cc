//s 14:24
//e 14:40
#include <bits/stdc++.h>

using namespace std;

int N, M;
int num[8];
int arr[8];

void selectRecursive(int index, int* ptrNum)
{
	if (index == M) {
		for (int i = 0; i < M; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int* it = ptrNum; it != num + N; ++it) {
		arr[index] = *it;
		selectRecursive(index + 1, it + 1);
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}

	sort(num, num + N);
	selectRecursive(0, num);

	return 0;
}