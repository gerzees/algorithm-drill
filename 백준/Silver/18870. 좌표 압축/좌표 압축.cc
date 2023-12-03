//14:07, 14:37
#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int sortedUnique[1000000];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 0;i < n;++i) {
		cin >> a[i];
	}

	for (int i = 0;i < n;++i) {
		sortedUnique[i] = a[i];
	}

	sort(sortedUnique, sortedUnique + n);

	int cnt = unique(sortedUnique, sortedUnique + n) - sortedUnique;

	for (int i = 0; i < n; ++i) {
		cout << lower_bound(sortedUnique, sortedUnique + cnt, a[i]) - sortedUnique << ' ';
	}

	return 0;
}