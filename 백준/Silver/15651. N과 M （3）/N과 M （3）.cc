// s 13:36
// e 13:44
#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[7];

void selectRecursive(int index)
{
	if (index == M) {
		for (int i = 0; i < M; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int num = 1;num <= N; ++num) {
		arr[index] = num;
		selectRecursive(index + 1);
	}
}

int main(void)
{
	cin >> N >> M;

	selectRecursive(0);

	return 0;
}