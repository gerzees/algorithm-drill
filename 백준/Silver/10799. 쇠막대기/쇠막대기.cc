// start 12:06 (break 40min)
// end: 14:57
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string brackets;
	cin >> brackets;
	stack<int> lasers;
	int count = 0;

	for (char bracket : brackets) {
		if (bracket == '(') {
			lasers.push(0);
			continue;
		}

		int laserCount = 0;
		if (lasers.top() == 0) {
			laserCount = 1; // new laser
			lasers.pop();
		}
		else {
			laserCount = lasers.top(); // 
			count += laserCount + 1;
			lasers.pop();
		}

		if (!lasers.empty()) {
			lasers.top() += laserCount;
		}
	}

	cout << count;
	return 0;
}