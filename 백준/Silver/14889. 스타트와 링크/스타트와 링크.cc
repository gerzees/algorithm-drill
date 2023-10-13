// s 22:10
// e 22:34
#include <bits/stdc++.h>
using namespace std;

int n;
int s[21][21];
int teamPermu[21];
int members[2][11];
int membersCnt[2];
int ans = INT_MAX;
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> s[i][j];
		}
	}

	fill(teamPermu + n / 2, teamPermu + n, 1);

	do {
		membersCnt[0] = 0;
		membersCnt[1] = 0;

		for (int i = 0;i < n;++i) {
			int team = teamPermu[i];
			members[team][membersCnt[team]++] = i;
		}

		int sumOfTeam0 = 0;
		int* team0 = members[0];
		for (int i = 0; i < n / 2; ++i) {
			for (int j = i + 1; j < n / 2; ++j) {
				sumOfTeam0 += s[team0[i]][team0[j]] + s[team0[j]][team0[i]];
			}
		}

		int sumOfTeam1 = 0;
		int* team1 = members[1];
		for (int i = 0; i < n / 2; ++i) {
			for (int j = i + 1; j < n / 2; ++j) {
				sumOfTeam1 += s[team1[i]][team1[j]] + s[team1[j]][team1[i]];
			}
		}

		int diff = sumOfTeam0 > sumOfTeam1 ? sumOfTeam0 - sumOfTeam1 : sumOfTeam1 - sumOfTeam0;
		if (diff == 0) {
			cout << 0;
			return 0;
		}

		if (diff < ans) {
			ans = diff;
		}

	} while (next_permutation(teamPermu, teamPermu + n));

	cout << ans;
	return 0;
}