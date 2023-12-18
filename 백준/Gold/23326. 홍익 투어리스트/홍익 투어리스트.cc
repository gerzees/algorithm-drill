// 9:37,10:18
#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int N, Q, cur = 1;
set<int> landmark;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) {
		int bLandmark;
		cin >> bLandmark;
		if (bLandmark) {
			landmark.insert(i);
		}
	}

	while (Q--) {
		int q;
		cin >> q;
		switch (q) {
		case 1: {
			int i;
			cin >> i;

			if (landmark.find(i) == landmark.end()) {
				landmark.insert(i);
			}
			else {
				landmark.erase(i);
			}
		}
			  break;
		case 2: {
			int x;
			cin >> x;
			cur = (cur + x - 1) % N + 1;
		}
			  break;
		case 3: {
			if (landmark.empty()) {
				cout << -1 << '\n';
				continue;
			}

			auto it = landmark.lower_bound(cur);
			if (it == landmark.end()) {
				cout << N - cur + *landmark.begin() << '\n';
			}
			else {
				cout << *it - cur << '\n';
			}
		}
			  break;
		}
	}
}