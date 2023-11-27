//13:18,13:40
#include<bits/stdc++.h>
using namespace std;

int cnt2[505];
int cnt5[505];

void countRecursive(int n, vector<bool>& bChecked)
{
	if (bChecked[n]) {
		return;
	}

	if (n % 2) {
		cnt2[n] = 0;
	}
	else {
		countRecursive(n / 2, bChecked);
		cnt2[n] = cnt2[n / 2] + 1;
	}
	if (n % 5) {
		cnt5[n] = 0;
	}
	else {
		countRecursive(n / 5, bChecked);
		cnt5[n] = cnt5[n / 5] + 1;
	}
}

int main(void)
{
	vector<bool> bChecked(505, false);

	int n;
	cin >> n;
	for (int i = 2;i <= n; ++i) {
		countRecursive(i, bChecked);
	}

	int totCnt2 = 0;
	int totCnt5 = 0;
	for (int i = n; i >= 1; --i) {
		totCnt2 += cnt2[i];
		totCnt5 += cnt5[i];
	}

	cout << min(totCnt2,totCnt5);

	return 0;
}