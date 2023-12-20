// 19:09,19:42
#include<bits/stdc++.h>
using namespace std;

int N;
pair<int, int> students[500'000];
multiset<int> teamSizeSet;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> students[i].first >> students[i].second;
	}

	sort(students, students + N);

	for (int i = N - 1; i >= 0; --i) {
		auto it = teamSizeSet.lower_bound(students[i].second);
		if (it == teamSizeSet.begin()) {
			teamSizeSet.insert(1);
		}
		else {
			int joinTeamSize = *--it;
			teamSizeSet.erase(it);
			teamSizeSet.insert(++joinTeamSize);
		}
	}

	cout << teamSizeSet.size();
}