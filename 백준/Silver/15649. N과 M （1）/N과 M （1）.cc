// s 22:25
// e 23:15
#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
int bInSeq[9];
void makeSequenceRecursive(int n, int m)
{
	if (m == 0) {
		int count = dq.size();

		for (int i = 0;i < count; ++i) {
			cout << dq[i] << ' ';
		}

		cout << '\n';

		return;
	}

	for (int i = 1;i <= n;++i) {
		
        if (bInSeq[i] > 0) {
			continue;
		}
        
		dq.push_back(i);
		bInSeq[i] = m;
		makeSequenceRecursive(n, m - 1);
		dq.pop_back();
		bInSeq[i] = 0;
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	makeSequenceRecursive(n, m);
	return 0;
}