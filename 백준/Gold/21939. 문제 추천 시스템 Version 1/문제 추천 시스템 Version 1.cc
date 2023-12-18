// 9:12, 9:33
#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
set<pair<int, int>> problems;
int l[100'001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		int p;
		cin >> p >> l[p];
		problems.insert({ l[p],p });
	}

	cin >> m;
	while (m--) {
		string com;
		cin >> com;
		if (com[0] == 'r') {
			int x;
			cin >> x;
			if (x == 1) {
				cout << prev(problems.end())->Y << '\n';
			}
			else {
				cout << problems.begin()->Y << '\n';
			}
		}
		else if (com[0] == 'a') {
			int p;
			cin >> p >> l[p];
			problems.insert({ l[p],p });
		}
		else {
			int p;
			cin >> p;
			problems.erase(problems.lower_bound({ l[p],p }));
		}
	}
}