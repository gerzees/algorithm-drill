//10:15, 10:58
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	const int E = 15, S = 28, M = 19;
	int e, s, m;
	cin >> e >> s >> m;
	s %= S;
	m %= M;

	int es = E * S;

	for (int i = e;i <= E * S; i += E) {
		if (i % S == s) {
			es = i;
			break;
		}
	}

	for (int i = es; i <= E * S * M; i += E * S) {
		if (i % M == m) {
			cout << i;

			return 0;
		}
	}

	return 0;
}