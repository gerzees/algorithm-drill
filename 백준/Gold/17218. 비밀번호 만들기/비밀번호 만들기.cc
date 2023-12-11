//20:26,21:06
#include<bits/stdc++.h>
using namespace std;

string a, b;
char tmp[40];
int unused;
char ans[40];
int ansLen;

void solve(int ai, int bi)
{
	if (ai >= a.size() - (ansLen - unused) || bi >= b.size() - (ansLen - unused)) {
		if (unused > ansLen) {
			ansLen = unused;

			for (int i = 0; i < ansLen; ++i) {
				ans[i] = tmp[i];
			}
		}

		return;
	}

	for (int i = bi; i < b.size(); ++i) {
		if (a[ai] != b[i]) continue;

		tmp[unused++] = a[ai];
		solve(ai + 1, i + 1);
		--unused;
		break;
	}

	solve(ai + 1, bi);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	solve(0, 0);

	for (int i = 0; i < ansLen; ++i) {
		cout << ans[i];
	}

	return 0;
}