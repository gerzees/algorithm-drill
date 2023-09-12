// s 13:03
// e
#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 
int dist[301][301];
const int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
const int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
vector<int> ans;

int main(void)
{

	int countCase;
	cin >> countCase;

	while (countCase--) {
		
		for (int i = 0;i < 301;++i) {
			fill(dist[i], dist[i] + 301, -1);
		}

		int boardSize;
		pair<int, int> start;
		pair<int, int> dest;
		queue<pair<int, int> > q;

		cin >> boardSize;
		cin >> start.X >> start.Y;
		dist[start.X][start.Y] = 0;
		q.push(start);
		cin >> dest.X >> dest.Y;

		while (!q.empty()) {
			pair<int, int>& cur = q.front();
			q.pop();

			if (cur == dest) {
				ans.push_back(dist[cur.X][cur.Y]);
				break;
			}

			for (int i = 0;i < 8;++i) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || nx >= boardSize || ny < 0 || ny >= boardSize) {
					continue;
				}

				if (dist[nx][ny] != -1) {
					continue;
				}

				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx,ny });
			}
		}
	}

	for (int dist : ans) {
		cout << dist << '\n';
	}

	return 0;
}