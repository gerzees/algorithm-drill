// s 13:03
// e 14:06
#include <bits/stdc++.h>
using namespace std;
// N극 0, S극 1
deque<char> gear[5];
// cog 12시 방향 idx=0
// cog 3시 방향 idx=2, cog 9시 방향 idx=6
// 극 같으면 회전 전달 x,  다르면 반대방향으로 회전
// dir 1: cw, -1: ccw
const int cw = 1;
const int ccw = -1;
const int cogL = 6;
const int cogR = 2;
bool bRotated[5];

void rotateGearRecursive(int idx, int dir)
{
	bRotated[idx] = true;

	if (idx >= 1 && !bRotated[idx - 1]) {
		if (gear[idx][cogL] != gear[idx - 1][cogR]) {
			rotateGearRecursive(idx - 1, dir == cw ? ccw : cw);
		}
	}
	if (idx < 3 && !bRotated[idx + 1]) {
		if (gear[idx][cogR] != gear[idx + 1][cogL]) {
			rotateGearRecursive(idx + 1, dir == cw ? ccw : cw);
		}
	}

	if (dir == cw) {
		gear[idx].push_front(gear[idx].back());
		gear[idx].pop_back();
	}
	else {
		gear[idx].push_back(gear[idx].front());
		gear[idx].pop_front();
	}
}


int main(void)
{
	for (int i = 0; i < 4; ++i) {
		string cogs;
		cin >> cogs;
		for (int j = 0; j < 8; ++j) {
			gear[i].push_back(cogs[j]);
		}
	}

	int k;
	cin >> k;
	while (k--) {
		int gearIdx;
		int dir;
		cin >> gearIdx >> dir;

		fill(bRotated, bRotated + 5, false);
		rotateGearRecursive(gearIdx - 1, dir);
	}

	int ans = 0;

	for (int i = 0; i < 4; ++i) {
		if (gear[i].front() == '1') {
			ans += 1 << i;
		}
	}

	cout << ans;

	return 0;
}