//9:25,11:43 시간 안에 못풀어서 풀이 보고 이해하고 다시 짜봄
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int schedule[105];
	bool bStuck[105];
	fill(schedule, schedule + 105, 0);
	fill(bStuck, bStuck + 105, false);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; ++i) {
		cin >> schedule[i];
	}

	int tot = 0;
	int stuckCount = 0;
	for (int cur = 0; cur < k; ++cur) {
		if (bStuck[schedule[cur]]) {
			continue;
		}

		if (stuckCount < n) {
			bStuck[schedule[cur]] = true;
			++stuckCount;
			continue;
		}

		vector<pair<int, int>> vec;
		vec.reserve(n);
		for (int stuck = 1; stuck <= k; ++stuck) {
			if (!bStuck[stuck]) {
				continue;
			}

			int usingTime = k;
			for (int t = cur + 1; t < k; ++t) {
				if (schedule[t] == stuck) {
					usingTime = t;
					break;
				}
			}

			vec.push_back({ usingTime, stuck });
		}

		sort(vec.begin(), vec.end());
		bStuck[vec.back().second] = false;
		bStuck[schedule[cur]] = true;
		++tot;
	}

	cout << tot;

	return 0;
}