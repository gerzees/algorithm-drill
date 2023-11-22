// 10:21,11:33
#include<bits/stdc++.h>

using namespace std;
int main(void)
{
	vector<pair<int, int>> flowers;
	flowers.reserve(100005);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int bloomMonth, bloomDay, fallMonth, fallDay;
		cin >> bloomMonth >> bloomDay >> fallMonth >> fallDay;
		flowers.push_back({ bloomMonth * 100 + bloomDay,fallMonth * 100 + fallDay });
	}

	sort(flowers.begin(), flowers.end());

	int fall_t = 301;
	int prev_fall_t = 301;
	const int end_t = 1130;
	int cntFlower = 0;

	for (int i = 0; i < flowers.size(); ++i) {
		int bloom, fall;
		tie(bloom, fall) = flowers[i];

		if (bloom > fall_t) {
			if (prev_fall_t <= fall_t || bloom > prev_fall_t) {
				break;
			}

			fall_t = prev_fall_t;
			++cntFlower;
		}

		if (fall > end_t) {
			fall_t = fall;
			++cntFlower;
			break;
		}


		prev_fall_t = max(prev_fall_t, fall);
	}

	if (fall_t > end_t) {
		cout << cntFlower;

		return 0;
	}

	cout << 0;

	return 0;
}