// s 20:58
// e 21:04
#include <bits/stdc++.h>

using namespace std;

int num[9];
int arr[9];
int N, M;

void selectRecursive(int countSelected)
{
	if (countSelected == M) {
		
		for (int i = 0; i < M; ++i) {
			cout << num[arr[i]] << ' ';
		}
		cout << '\n';
		
		return;
	}

	int st = countSelected == 0 ? 0 : arr[countSelected - 1];

	for (int i = st; i < N; ++i) {
		arr[countSelected] = i;
		selectRecursive(countSelected + 1);
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