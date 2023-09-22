// s 21:43
// e 22:05
#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[9];
int arr[9];

void selectRecursive(int cntSelected, int start)
{
	if (cntSelected == M) {
		for (int i = 0; i < M; ++i) {
			cout << num[arr[i]] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = start; i < N; ++i) {
		arr[cntSelected] = i;
		selectRecursive(cntSelected + 1, i + 1);

		for (int next = i + 1; next < N && num[i] == num[next]; ++next) {
			++i;
		}
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}

	sort(num, num + N);
	selectRecursive(0, 0);

	return 0;
}