//s20:37
//e21:36
#include <bits/stdc++.h>
#define S first
#define W second
//S:내구도, W:무게
using namespace std;

int n;
int s[9];
int w[9];
int ans;
int brokenCnt;
bool bDone;

void hitEggsRecursive(int cur)
{
	if (ans == n) {
		return;
	}

	if (cur == n) {
		return;
	}

	if (s[cur] <= 0) {
		hitEggsRecursive(cur + 1);
		return;
	}

	bool bOnlyCurLeft = true;
	for (int i = 0; i < n; ++i) {
		if (i == cur) {
			continue;
		}

		if (s[i] <= 0) {
			continue;
		}

		bOnlyCurLeft = false;
		s[cur] -= w[i];
		s[i] -= w[cur];

		if (s[cur] <= 0) {
			++brokenCnt;
		}

		if (s[i] <= 0) {
			++brokenCnt;
		}

		if (ans < brokenCnt) {
			ans = brokenCnt;
		}

		hitEggsRecursive(cur + 1);

		if (s[cur] <= 0) {
			--brokenCnt;
		}

		if (s[i] <= 0) {
			--brokenCnt;
		}

		s[cur] += w[i];
		s[i] += w[cur];
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i] >> w[i];
	}

	hitEggsRecursive(0);

	cout << ans;

	return 0;
}