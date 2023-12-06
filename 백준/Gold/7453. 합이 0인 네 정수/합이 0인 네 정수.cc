// 9:10,9:35
#include<bits/stdc++.h>
using namespace std;

int n;
int A[4000];
int B[4000];
int C[4000];
int D[4000];
vector<int> AB;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	AB.reserve(n * n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			AB.push_back(-A[i] - B[j]);
		}
	}

	sort(AB.begin(), AB.end());

	long long ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans += upper_bound(AB.begin(), AB.end(), C[i] + D[j]) - lower_bound(AB.begin(), AB.end(), C[i] + D[j]);
		}
	}

	cout << ans;

	return 0;
}