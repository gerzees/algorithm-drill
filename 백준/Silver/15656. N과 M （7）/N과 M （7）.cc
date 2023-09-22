// s 20:30
// e 20:38
#include <bits/stdc++.h>
using namespace std;

int num[8];
int arr[8];
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

	for (int i = 0; i < N; ++i) {
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