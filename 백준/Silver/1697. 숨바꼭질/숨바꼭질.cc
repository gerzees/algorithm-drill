// start 10:54
// end

#include <bits/stdc++.h>
using namespace std;

bool bVisited[200002];

int main(void)
{
	int FJ, cow;
	cin >> FJ >> cow;

	if (FJ == cow) {
		cout << 0;
		return 0;
	}

	if (FJ > cow) {
		cout << FJ - cow;
		return 0;
	}

	int min = cow - FJ;
	queue<int> Q;
	int minutes = 0;
	const int END = -1;
	Q.push(FJ);
	bVisited[FJ] = true;
	Q.push(END);

	while (true) {
		int cur = Q.front();
		Q.pop();


		if (cur == END) {
			if (Q.empty()) {
				break;
			}
			++minutes;
			Q.push(END);
			continue;
		}

		if (cur == cow) {
			cout << (minutes < min ? minutes : min);
			return 0;
		}

		if (cur > 0 && !bVisited[cur - 1]) {
			Q.push(cur - 1);
			bVisited[cur - 1] = true;
		}

		if (2 * cur < cow) {
			if (!bVisited[cur + 1]) {
				Q.push(cur + 1);
				bVisited[cur + 1] = true;
			}

			if (!bVisited[2 * cur]) {
				Q.push(2 * cur);
				bVisited[2 * cur] = true;
			}
			continue;
		}

		if (2 * cur == cow) {
			Q.push(cow);
			bVisited[cow] = true;
			continue;
		}

		// 2*cur>cow
		int dist = minutes;

		if (cow - cur <= 2 * cur - cow + 1) {
			dist += cow - cur;
		}
		else {
			dist += 2 * cur - cow + 1;
		}

		if (dist < min) {
			min = dist;
		}
	}

	cout << min;

	return 0;
}