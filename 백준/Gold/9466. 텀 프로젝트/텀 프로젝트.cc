// s 14:28
// e 15:31
#include <bits/stdc++.h>
using namespace std;
int selection[100001];
int dist[100001];
int main(void)
{
	int t;
	cin >> t;
	vector<int> ans;

	while (t--) {
		int n;
		cin >> n;

		fill(dist, dist + n, -1);

		for (int i = 0;i < n;++i) {
			int selected;
			cin >> selected;
			selection[i] = selected - 1;
		}

		queue<int> Q;
		int count = 0;
		int noTeamCount = 0;

		for (int i = 0;i < n;++i) {
			if (dist[i] != -1) {
				continue;
			}

			int teamStart = count;
			Q.push(i);
			dist[i] = count++;

			while (!Q.empty()) {
				int cur = Q.front();
				Q.pop();

				int selected = selection[cur];
				if (dist[selected] == -1) {
					Q.push(selected);
					dist[selected] = count++;
					continue;
				}

				if (dist[selected] >= teamStart) {
					noTeamCount += dist[selected] - teamStart;
				}
				else {
					noTeamCount += count - teamStart;
				}
			}
		}

		ans.push_back(noTeamCount);
	}

	for (int count : ans) {
		cout << count << '\n';
	}

	return 0;
}