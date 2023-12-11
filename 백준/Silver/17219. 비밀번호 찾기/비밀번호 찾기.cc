//20:20, 20:26
#include<bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, string> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string addr, pw;
		cin >> addr >> pw;
		mp[addr] = pw;
	}

	while (m--) {
		string addr;
		cin >> addr;
		cout << mp[addr] << '\n';
	}

	return 0;
}