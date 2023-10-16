// s 17:00
// e 17:10
#include<bits/stdc++.h>
using namespace std;

int nums[2000002];
int n;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		int i;
		cin >> i;
		++nums[i + 1000000];
	}

	for (int i = 0;i < 2000002;++i) {
		while (nums[i]--) {
			cout << i - 1000000 << '\n';
		}
	}

	return 0;
}