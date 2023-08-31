// start	 10:27am
// end		
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string dataset;
	getline(cin, dataset);
	while (dataset.length() > 1 || dataset[0] != '.') {
		char charStack[100];
		int top = 0;
		bool bBalanced = true;

		for (int i = 0; i < dataset.length() - 1 && bBalanced; ++i) {

			switch (dataset[i]) {

			case '(':
			{
				charStack[top++] = '(';
			}
			break;

			case ')':
			{
				bBalanced = charStack[--top] == '(';
			}
			break;

			case '[':
			{
				charStack[top++] = '[';
			}
			break;

			case ']':
			{
				bBalanced = charStack[--top] == '[';
			}
			break;

			default://skip not bracket 
				break;
			}
		}

		if (bBalanced && top == 0) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}

		getline(cin, dataset);
	}
	return 0;
}