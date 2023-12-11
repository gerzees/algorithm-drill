//21:19,22:40
#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> ump;
int n;
int t;
vector<int> cnts;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cnts.clear();
		ump.clear();

		cin >> n;

		while (n--) {
			string name, category;
			cin >> name >> category;

			if (ump.find(category) == ump.end()) ump.insert({ category,1 });
			else ++ump[category];
		}

		int ans = 0;

		for (auto& e : ump) {
			ans = ans + ans * e.second + e.second;
		}

		cout << ans << '\n';
	}


	return 0;
}