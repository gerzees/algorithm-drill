// 11:55,12:07
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	string line;
	cin >> line;

	int sum = 0;
	int num = 0;
	bool bMinus = false;
	for (char c : line) {
		switch (c) {
		case '-':
			if (bMinus) {
				sum -= num;
				num = 0;
			}
			else {
				bMinus = true;
				sum += num;
				num = 0;
			}
			break;
		case '+':
			if (bMinus) {
				sum -= num;
				num = 0;
			}
			else {
				sum += num;
				num = 0;
			}
			break;
		default:
			num *= 10;
			num += c - '0';
			break;
		}
	}

	if (bMinus) {
		sum -= num;
	}
	else {
		sum += num;
	}

	cout << sum;

	return 0;
}