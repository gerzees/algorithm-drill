// start 21:28

#include <bits/stdc++.h>

using namespace std;

int MAZE[100][100];
bool bVisited[100][100];

int main(void)
{
	//pair<pair<int,int>,int> 좌표, 거리
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	for (int r = 0; r < N; ++r) {
		string line;
		cin >> line;

		for (int c = 0; c < M; ++c) {
			MAZE[r][c] = line[c] == '0' ? 0 : 1;
		}
	}

	queue<pair<pair<int, int>, int>> Q;
	Q.push({ {0,0},1 });
	bVisited[0][0] = true;

	while (!Q.empty()) {
		pair<pair<int, int>, int> cur = Q.front();
		Q.pop();

		if (cur.first.first == N - 1 && cur.first.second == M - 1) {
			cout << cur.second;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			const int dr[] = { 1,-1,0,0 };
			const int dc[] = { 0,0,1,-1 };
			pair<int, int> nextPos = { cur.first.first + dr[i],cur.first.second + dc[i] };


			if (nextPos.first >= 0 && nextPos.first < N && nextPos.second >= 0 && nextPos.second < M) {

				if (!bVisited[nextPos.first][nextPos.second]) {
					bVisited[nextPos.first][nextPos.second] = true;

					if (MAZE[nextPos.first][nextPos.second] == 1) {
						Q.push({ nextPos,cur.second + 1 });
					}
				}
			}
		}
	}

	return 0;
}