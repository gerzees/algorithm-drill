//8:38,8:50 주먹구구
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	// 1 2|2 333 4|444 55555 666666
	//3 7
	int a, b;
	cin >> a >> b;

	int cur = 1;
	int num = 1;
	int sum = 0;
	while (true) {
		for (int i = 0;i < num; ++i) {
			if (cur > b) {
				cout << sum;

				return 0;
			}
			if (cur >= a && cur <= b) {
				sum += num;
			}
			++cur;
		}
		++num;
	}


	return 0;
}