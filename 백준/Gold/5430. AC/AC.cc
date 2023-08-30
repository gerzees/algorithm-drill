#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int countTestCase;
	cin >> countTestCase;

	for (int i = 0;i < countTestCase;++i) {
		string command;
		int listLength;
		cin >> command >> listLength;
		deque<int> integerList(listLength);
		char bracket;
		char comma;

		cin >> bracket;

		if (listLength > 0) {

			for (int j = 0;j < listLength - 1;++j) {
				cin >> integerList[j] >> comma;
			}

			cin >> integerList[listLength - 1];
		}

		cin >> bracket;

		bool bReverse = false;
		bool bError = false;

		for (int j = 0; j < command.length();++j) {
			if (command[j] == 'R') {
				bReverse = !bReverse;
			}
			else { // command[j] == 'D'
				if (integerList.size() == 0) {
					bError = true;
					break;
				}
				if (bReverse) {
					integerList.pop_back();
				}
				else {
					integerList.pop_front();
				}
			}
		}

		if (bError) {
			cout << "error\n";
			continue;
		}

		cout << '[';

		if (bReverse && integerList.size() > 0) {
			for (int j = integerList.size() - 1;j > 0;--j) {
				cout << integerList[j] << ',';
			}

			cout << integerList.front();
		}
		else if (integerList.size() > 0) {
			for (int j = 0; j < integerList.size() - 1;++j) {
				cout << integerList[j] << ',';
			}

			cout << integerList.back();
		}

		cout << "]\n";
	}

	return 0;
}