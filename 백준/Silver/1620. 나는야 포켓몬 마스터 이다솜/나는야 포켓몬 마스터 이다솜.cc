//15:36, 16:12
#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;
vector<string> v;
int n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	mp.reserve(1'000'000);
	v.reserve(1'000'000);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		string name;
		cin >> name;
		mp.insert({ name,i });
		v.push_back(name);
	}

	while (m--) {
		string p;
		cin >> p;
		if (!isalpha(p[0])) {
			cout << v[stoi(p) - 1] << '\n';
		}
		else {
			cout << mp[p] << '\n';
		}
	}

	return 0;
}