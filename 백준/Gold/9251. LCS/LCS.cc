// 10:13- 11:07
// 풀이 보고 풀었음
#include<bits/stdc++.h>
using namespace std;

string arr1, arr2;
int d[1005][1005];
int main(void)
{
	cin >> arr1 >> arr2;
	d[1][1] = arr1[0] == arr2[0] ? 1 : 0;

	for (int i = 1;i <= arr1.size(); ++i) {
		for (int j = 1; j <= arr2.size(); ++j) {
			if (arr1[i - 1] == arr2[j - 1]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
		if (arr1[i - 1] == arr2[0]) {
		d[i][1] = d[i - 1][0] + 1;
		}
	}

	cout << d[arr1.size()][arr2.size()];

	return 0;
}