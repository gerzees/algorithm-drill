//15:43, 15:54
#include<bits/stdc++.h>
using namespace std;

int t;
int k;
char c;
int n;

multiset<int> ms;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		ms.clear();
		cin >> k;
		while (k--) {
			cin >> c >> n;

			if (c == 'I') {
				ms.insert(n);
			}
			else {
				if (ms.empty()) {
					continue;
				}

				if (n == 1) {
					auto target = prev(ms.end());
					ms.erase(target);
				}
				else {
					auto target = ms.begin();
					ms.erase(target);
				}
			}
		}

		if (ms.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
		}
	}

}