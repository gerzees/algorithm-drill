// s 22:06
// e 22;12
#include<bits/stdc++.h>
using namespace std;

int N, M;
int num[8];
int arr[8];

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
		arr[cntSelected] = i;
		selectRecursive(cntSelected + 1);

		for (int next = i + 1; next < N && num[next] == num[i]; ++next) {
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