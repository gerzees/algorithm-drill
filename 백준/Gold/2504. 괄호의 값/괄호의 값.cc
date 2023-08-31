//start 11:04am
//end 11:56am
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string brackets;
	cin >> brackets;
	char charStack[31];
	unsigned long long valueStack[16] = { 0, };
	int top = 0;

	for (char bracket : brackets) {
		if (bracket == '(' || bracket == '[') {
			charStack[top++] = bracket;
			continue;
		}

		if (top == 0) {
			cout << 0;
			return 0;
		}

		char pair = charStack[--top];

		if (bracket == ')' && pair == '[' || bracket == ']' && pair == '(') {
			cout << 0;
			return 0;
		}

		unsigned long long innerValue = valueStack[top + 1];
		valueStack[top + 1] = 0;

		if (bracket == ')' && pair == '(') {
			// value : 2 (x)(x) (())
			valueStack[top] += innerValue == 0 ? 2 : 2 * innerValue;
		}
		else {
			// value : 3
			valueStack[top] += innerValue == 0 ? 3 : 3 * innerValue;
		}
	}

	if (top == 0) {
		cout << valueStack[top];
	}
	else {
		cout << 0;
	}

	return 0;
}