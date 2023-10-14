// s 13:43
// e 14:38
#include<bits/stdc++.h>
using namespace std;

int board[2][101][101];
bool bRamped[101];
int n;
int l;
int ans;

int main(void)
{
	cin >> n >> l;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[0][i][j];
			board[1][j][i] = board[0][i][j];
		}
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			int* heights = board[i][j];
			fill(bRamped, bRamped + n, false);
			bool bGoThrough = true;

			for (int cur = 0; cur + 1 < n; ++cur) {
				int diff = heights[cur + 1]- heights[cur];
				if (diff == 0) {
					continue;
				}
				else if (diff > 1 || diff < -1) {
					bGoThrough = false;
					break;
				}
				else if (diff == 1) {// 오르막 경사로 필요
					int base = cur;
					int cnt = 0;
					for (; cnt < l; ++cnt) {
						if (base - cnt < 0 || bRamped[base - cnt] || heights[base] != heights[base - cnt]) {
							break;
						}
					}

					if (cnt != l) {
						bGoThrough = false;
						break;
					}

					for (cnt = 0; cnt < l; ++cnt) {
						bRamped[base - cnt] = true;
					}
				}
				else { // 내리막 경사로 필요
					int base = cur + 1;
					int cnt = 0;
					for (; cnt < l; ++cnt) {
						if (base + cnt >= n || bRamped[base + cnt] || heights[base] != heights[base + cnt]) {
							break;
						}
					}

					if (cnt != l) {
						bGoThrough = false;
						break;
					}

					for (cnt = 0; cnt < l; ++cnt) {
						bRamped[base + cnt] = true;
					}
				}
			}

			if (bGoThrough) {
				++ans;
			}
		}
	}

	cout << ans;

	return 0;
}