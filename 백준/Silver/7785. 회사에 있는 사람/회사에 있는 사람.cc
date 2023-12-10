//14:47,15:02
#include<bits/stdc++.h>
using namespace std;

pair<string, int> logs[1'000'000];
int n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		string log;
		cin >> logs[i].first >> log;
		if (log[0] == 'e') {
			logs[i].second = 1;
		}
		else {
			logs[i].second = -1;
		}
	}

	sort(logs, logs + n);

	string& cur = logs[n - 1].first;
	int bPresent = logs[n - 1].second;

	for (int i = n - 2; i >= 0; --i) {
		if (cur != logs[i].first) {
			if (bPresent) {
				cout << cur << '\n';
			}

			cur = logs[i].first;
			bPresent = logs[i].second;
		}
		else {
			bPresent += logs[i].second;
		}
	}

	if (bPresent) {
		cout << cur << '\n';
	}

	return 0;
}