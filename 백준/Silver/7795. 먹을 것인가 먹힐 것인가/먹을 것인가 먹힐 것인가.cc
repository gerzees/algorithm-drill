// s 11:00
// e 11:56
#include<bits/stdc++.h>

using namespace std;

vector<int> AGroup(20000);
vector<int> BGroup(20000);

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		int countA;
		int countB;
		cin >> countA >> countB;
		AGroup.clear();
		BGroup.clear();

		for (int i = 0; i < countA; ++i) {
			int A;
			cin >> A;
			AGroup.push_back(A);
		}

		for (int i = 0; i < countB; ++i) {
			int B;
			cin >> B;
			BGroup.push_back(B);
		}

		sort(AGroup.begin(), AGroup.end());
		sort(BGroup.begin(), BGroup.end());
		int countTotalPair = 0;
		int AIdx = 0;
		int BIdx = 0;

		while (AIdx < AGroup.size() && BIdx < BGroup.size()) {

			for (;BIdx < BGroup.size() && AGroup[AIdx] > BGroup[BIdx]; ++BIdx) {
			}

			int differentAIdx = AIdx + 1;
			for (;differentAIdx < AGroup.size() && AGroup[differentAIdx] == AGroup[AIdx]; ++differentAIdx) {
			}

			countTotalPair += BIdx * (differentAIdx - AIdx);
			AIdx = differentAIdx;
		}

		if (AIdx < AGroup.size()) {
			countTotalPair += BIdx * (AGroup.size() - AIdx);
		}

		cout << countTotalPair << '\n';
	}

	return 0;
}