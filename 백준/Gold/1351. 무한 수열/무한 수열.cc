//13:45, 14:17
#include<bits/stdc++.h>
using namespace std;
unordered_map<long long, long long> a;
long long n;
int p, q;

long long getA(long long n) {

	if (a.find(n) != a.end()) return a[n];

	long long a_n = getA(n / p) + getA(n / q);
	a[n] = a_n;
	return a_n;
}

int main(void) {
	a[0] = 1;
	cin >> n >> p >> q;
	cout << getA(n);
}