// s 18:49
// e 19:17
#include <bits/stdc++.h>

using namespace std;
vector<long long> elements;
int main(void)
{
	int cnt;
	cin >> cnt;
	string element;

	for (int i = 0; i < cnt; ++i) {
		cin >> element;
		reverse(element.begin(), element.end());
		elements.push_back(stoll(element));
	}

	sort(elements.begin(), elements.end());
	for (long long e : elements) {
		cout << e << '\n';
	}

	return 0;
}