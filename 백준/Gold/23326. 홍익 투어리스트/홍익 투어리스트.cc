// 9:37,10:07
#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int N, Q, cur = 1;
int bLandmark[500'005];
set<int> area[2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	for (int i = 1; i < N; ++i) {
		cin >> bLandmark[i];
		area[bLandmark[i]].insert(i);
	}
	cin >> bLandmark[0];
	area[bLandmark[0]].insert(0);

	while (Q--) {
		int q;
		cin >> q;
		switch (q) {
		case 1: {
			int i;
			cin >> i;
			i %= N;
			area[bLandmark[i]].erase(i);
			bLandmark[i] ^= 1;
			area[bLandmark[i]].insert(i);
		}
			  break;
		case 2: {
			int x;
			cin >> x;
			cur = (cur + x) % N;
		}
			  break;
		case 3: {
			if (area[1].empty()) {
				cout << -1 << '\n';
				continue;
			}

			auto landmarkIt = area[1].lower_bound(cur);
			if (landmarkIt == area[1].end()) {
				landmarkIt = area[1].begin();
				cout << N - cur + *landmarkIt << '\n';
			}
			else {
				cout << *landmarkIt - cur << '\n';
			}
		}
			break;
		}
	}
}