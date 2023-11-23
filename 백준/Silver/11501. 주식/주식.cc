//8:30, 10:12
#include<bits/stdc++.h>
using namespace std;

int p[1000010];
vector<int> saleIdx;
int main(void)
{
	saleIdx.reserve(1000010);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		fill(p, p + n, 0);
		saleIdx.clear();

		cin >> p[0];
		for (int i = 1; i < n; ++i) {
			cin >> p[i];
			if (p[i] < p[i - 1]) {
				while (!saleIdx.empty()) {
					if (p[saleIdx.back()] > p[i - 1]) {
						break;
					}

					saleIdx.pop_back();
				}

				saleIdx.push_back(i - 1);
			}
		}

		while (!saleIdx.empty()) {
			if (p[saleIdx.back()] > p[n - 1]) {
				break;
			}

			saleIdx.pop_back();
		}

		saleIdx.push_back(n - 1);


		long long profitSum = 0;

		for (int j = 0; j < saleIdx.size(); ++j) {
			int purchaseStart = j == 0 ? 0 : saleIdx[j - 1] + 1;
			long long profit = 0ll;

			for (int i = purchaseStart; i < saleIdx[j]; ++i) {
				profit += p[saleIdx[j]] - p[i];
			}

			profitSum += profit;
		}

		cout << profitSum << '\n';
	}

	return 0;
}