//s 11:54
// e
#include <bits/stdc++.h>

using namespace std;

vector<int> vFrom;
vector<int> vTo;

int hanoiRecursive(int N, int from, int to)
{
	if (N == 0) {
		return 0;
	}

	int aux = 6 - (from + to);
	int count = hanoiRecursive(N - 1, from, aux);
	++count;
	vFrom.push_back(from);
	vTo.push_back(to);
	count += hanoiRecursive(N - 1, aux, to);

	return count;
}
int main(void)
{
	int N;
	cin >> N;
	// N<=20 count <=1048575

	cout << hanoiRecursive(N, 1, 3) << '\n';

	for (int i = 0;i < vFrom.size();++i) {
		cout << vFrom[i] << ' ' << vTo[i] << '\n';
	}

	return 0;
}