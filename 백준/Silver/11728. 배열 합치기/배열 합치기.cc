// s 14:03
// e 14:09
#include<bits/stdc++.h>
using namespace std;

int A[1000000];
int B[1000000];
int merged[2000000];
int n, m;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	
	for (int i = 0; i < m; ++i) {
		cin >> B[i];
	}

	int ia = 0;
	int ib = 0;
	for (int i = 0; i < n + m; ++i) {
		if (ia == n) {
			merged[i] = B[ib++];
			continue;
		}

		if (ib == m) {
			merged[i] = A[ia++];
			continue;
		}

		merged[i] = A[ia] < B[ib] ? A[ia++] : B[ib++];
	}

	for (int i = 0; i < n + m; ++i) {
		cout << merged[i] << ' ';
	}

	return 0;
}