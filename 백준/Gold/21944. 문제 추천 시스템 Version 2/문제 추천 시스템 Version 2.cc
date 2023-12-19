// 14:07, 15:11
#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int N, L, G, M, P;
set<pair<int, int>> probByG[101];
set<int> probByL[101];
set<int> level;

pair<int, int> probs[100'001];
set<int> pSet[2][100];//problems[0] 난이도별 문제, problems[1] 분류별 문제
const int byL = 0;
const int byG = 1;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		cin >> P >> L >> G;
		probs[P] = { L,G };
		probByG[G].insert({ L,P });
		probByL[L].insert(P);
		level.insert(L);
	}

	cin >> M;
	while (M--) {
		string com;
		cin >> com;
		switch (com.front()) {
		case 'r':
		{
			int x;
			switch (com.back()) {
			case 'd':
			{
				cin >> G >> x;
				if (x == 1) {
					cout << prev(probByG[G].end())->second << '\n';

				}
				else {
					cout << probByG[G].begin()->second << '\n';
				}
			}
			break;
			case '2':
			{
				cin >> x;
				if (x == 1) {
					int l = *prev(level.end());
					cout << *prev(probByL[l].end()) << '\n';
				}
				else {
					int l = *level.begin();
					cout << *probByL[l].begin() << '\n';
				}
			}
			break;
			case '3':
			{
				cin >> x >> L;
				if (x == 1) {
					auto it = level.lower_bound(L);
					if (it == level.end()) {
						cout << -1 << '\n';
					}
					else {
						cout << *probByL[*it].begin() << '\n';
					}
				}
				else {
					auto it = level.lower_bound(L);
					if (it == level.begin()) {
						cout << -1 << '\n';
					}
					else {
						cout << *prev(probByL[*prev(it)].end()) << '\n';
					}
				}
			}
			break;
			}
		}
		break;
		case 'a':
		{
			cin >> P >> L >> G;
			probs[P] = { L,G };
			probByG[G].insert({ L,P });
			probByL[L].insert(P);
			level.insert(L);
		}
		break;
		case 's':
		{
			cin >> P;
			tie(L, G) = probs[P];
			probByG[G].erase({ L,P });
			probByL[L].erase(P);
			if (probByL[L].empty()) {
				level.erase(L);
			}
		}
		break;
		}
	}
}