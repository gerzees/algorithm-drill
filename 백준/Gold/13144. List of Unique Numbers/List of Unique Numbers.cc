//14:09, 14:50
#include<bits/stdc++.h>
using namespace std;

int n;
int a[100000];
vector<bool> bIn(100000, false);
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long cnt = 0;
	int en = 0;
    
	for (int st = 0; st < n; ++st) {
		while (en < n && !bIn[a[en]]) {
			cnt += en - st + 1;
			bIn[a[en++]] = true;
		}

		if (en == n) {
			break;
		}

		bIn[a[st]] = false;
	}

	cout << cnt;

	return 0;
}