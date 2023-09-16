// s 20:50
// e 23:04
// s 16:28
// e 16:34
#include <bits/stdc++.h>
using namespace std;

int dist[200001];
int main(void)
{
	int start;
	int target;
	cin >> start >> target;

	if (start < target) {
		fill(dist, dist + 2 * target, -1);
		queue<int> teleportQ;
		queue<int> movingQ;

		if (start != 0) {
			teleportQ.push(start);
			movingQ.push(start);
			dist[start] = 0;
		}
		else {
			movingQ.push(0);
			dist[0] = 0;
		}

		bool bArrive = false;

		while (true) {

			while (!teleportQ.empty()) {
				int cur = teleportQ.front();
				teleportQ.pop();

				for (;cur < target;cur *= 2) {
					if (dist[2 * cur] != -1) {
						continue;
					}

					if (2 * cur == target) {
						cout << dist[cur];
						return 0;
					}

					movingQ.push(2 * cur);
					dist[2 * cur] = dist[cur];
				}

			}

			int movingCount = movingQ.size();

			while (movingCount--) {
				int cur = movingQ.front();
				movingQ.pop();

				if (cur + 1 == target || cur - 1 == target) {
					cout << dist[cur] + 1;
					return 0;
				}

				if (cur < target && dist[cur + 1] == -1) {
					teleportQ.push(cur + 1);
					movingQ.push(cur + 1);
					dist[cur + 1] = dist[cur] + 1;
				}

				if (cur > 1 && dist[cur - 1] == -1) {
					teleportQ.push(cur - 1);
					movingQ.push(cur - 1);
					dist[cur - 1] = dist[cur] + 1;
				}
			}
		}
	}
	else {
		cout << start - target;
	}

	return 0;
}