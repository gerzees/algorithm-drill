// s 20:51
// e 21:33
#include <bits/stdc++.h>

using namespace std;

map<int,pair<int, int>> M;// key: number, pair.first: freq, pair.second: order
vector<tuple<int, int, int>> V;
bool cmpTuple(const tuple<int, int, int>& lhs, const tuple<int, int, int>& rhs) {
	if (get<0>(lhs) > get<0>(rhs)) {
		return true;
	}

	if (get<0>(lhs) < get<0>(rhs)) {
		return false;
	}

	if (get<1>(lhs) < get<1>(rhs)) {
		return true;
	}

	return false;
}
int main(void)
{
	int cnt, limit;
	cin >> cnt >> limit;
	for (int i = 0; i < cnt; ++i) {
		int num;
		cin >> num;
		if (M.find(num) != M.end()) {
			++M[num].first;
		}
		else {
			M[num] = { 1,i };
		}
	}

	for (map<int, pair<int, int>>::const_iterator it = M.begin(); it != M.end(); ++it) {
		V.push_back({ it->second.first,it->second.second, it->first });
	}

	sort(V.begin(), V.end(), cmpTuple);

	for (const auto& t : V) {
		int freq = get<0>(t);
		int num = get<2>(t);
		for (int i = 0; i < freq; ++i) {
			cout << num << ' ';
		}
	}

	return 0;
}