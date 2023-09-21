// s 12:57
// e 13:14
#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int arr[8];

void selectRecursive(int num, int countSelect)
{
	if (countSelect > n - num + 1) {
		return;
	}

	if (countSelect == 0) {

		for (int i = 0;i < m;++i) {
			cout << arr[i] << ' ';
		}

		cout << '\n';

		return;
	}

	arr[m - countSelect] = num;
	selectRecursive(num + 1, countSelect - 1);//select

	selectRecursive(num + 1, countSelect);//not select
}

int main(void)
{
	cin >> n >> m;
	selectRecursive(1, m);
	return 0;
}