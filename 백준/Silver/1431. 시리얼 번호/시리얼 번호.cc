// s16:33
// e16:53
#include<bits/stdc++.h>
using namespace std;

bool cmp(const string& l, const string& r)
{
	if (l.size() < r.size()) {
		return true;
	}

	if (l.size() > r.size()) {
		return false;
	}


	int lsum = 0;
	int rsum = 0;
	for (int i = 0; i < l.size(); ++i) {
		if (l[i] >= '0'&& l[i] <= '9') {
			lsum += l[i] - '0';
		}

		if (r[i] >= '0' && r[i] <= '9') {
			rsum += r[i] - '0';
		}
	}

	if (lsum < rsum) {
		return true;
	}

	if (lsum > rsum) {
		return false;
	}


	if (l.compare(r) < 0) {
		return true;
	}
	else {
		return false;
	}
}

string serialNumbers[51];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> serialNumbers[i];
	}

	sort(serialNumbers, serialNumbers + n, cmp);
	for (int i = 0; i < n; ++i) {
		cout << serialNumbers[i] << '\n';
	}

	return 0;
}