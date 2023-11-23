// 16:21, 16:41
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int pos[50];
	int posIdx = 0;
	int neg[50];
	int negIdx = 0;
	int zeroCnt = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (num == 0) {
			++zeroCnt;
		}
		else if (num > 0) {
			pos[posIdx++] = num;
		}
		else {
			neg[negIdx++] = num;
		}
	}

	sort(pos, pos + posIdx);
	sort(neg, neg + negIdx);
	int sum = 0;
	int i;
	for (i = posIdx - 1; i > 0; i -= 2) {
		if (pos[i] == 1 || pos[i - 1] == 1) {
			sum += pos[i] + pos[i - 1];
			continue;
		}

		sum += pos[i] * pos[i - 1];
	}

	if (i == 0) {
		sum += pos[i];
	}

	for (i = 0; i < negIdx - 1; i += 2) {
		sum += neg[i] * neg[i + 1];
	}

	if (i == negIdx - 1 && zeroCnt == 0) {
		sum += neg[i];
	}

	cout << sum;
	return 0;
}