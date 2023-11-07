// s 18:49
// e 19:16
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
		long long reversed = 0;
		string::reverse_iterator rIterOfElement = element.rbegin();
		for (;*rIterOfElement == '0'; ++rIterOfElement) {
		}
		for (;rIterOfElement != element.rend(); ++rIterOfElement) {
			reversed *= 10;
			reversed += *rIterOfElement - '0';
		}
		elements.push_back(reversed);
	}

	sort(elements.begin(), elements.end());
	for (long long e : elements) {
		cout << e << '\n';
	}

	return 0;
}