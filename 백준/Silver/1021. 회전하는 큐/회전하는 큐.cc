#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	deque<int> dq(N);
	int count = 0;

	for (int i = 0; i < N; ++i)
	{
		dq[i] = i + 1;
	}

	for (int i = 0;i < M;++i)
	{
		int n;
		cin >> n;

		{
			int leftShiftCount = 0;
			while (n != dq.front())
			{
				dq.push_back(dq.front());
				dq.pop_front();
				++leftShiftCount;
			}
			int rightShiftCount = dq.size() - leftShiftCount;
			count += leftShiftCount < rightShiftCount ? leftShiftCount : rightShiftCount;
			dq.pop_front();
		}
	}

	cout << count;

	return 0;
}