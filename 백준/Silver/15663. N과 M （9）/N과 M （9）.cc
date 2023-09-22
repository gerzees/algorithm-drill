// s 21:05
// e 21:43
#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[9];
int arr[9];
bool bUsed[9];

void selectRecursive(int cntSelected)
{
	if (cntSelected == M) {

		for (int i = 0; i < M; ++i) {
			cout << num[arr[i]] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < N; ++i) {
		if (bUsed[i]) {
			continue;
		}

		arr[cntSelected] = i;
		bUsed[i] = true;
		selectRecursive(cntSelected + 1);
		bUsed[i] = false;

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

	selectRecursive(0);

	return 0;
}