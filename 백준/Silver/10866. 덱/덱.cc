#include <bits/stdc++.h>

using namespace std;

//input integer 1<= <=100,000
constexpr int MX = 10000;

int main(void)
{
	int deq[MX * 2 + 1];
	int N; // 1<= <=10,000
	int head = MX;
	int tail = MX;
	string command;
	cin >> N;

	for (int i = 0;i < N;++i)
	{
		cin >> command;
		switch (command[0])
		{
		case 'p':
		{
			switch (command[5])
			{
			case 'f': // push_front
			{
				cin >> deq[--head];
			}
			break;

			case 'b': // push_back
			{
				cin >> deq[tail++];
			}
			break;

			case 'r': // pop_front
			{
				cout << (head < tail ? deq[head++] : -1) << '\n';
			}
			break;

			case 'a': // pop_back
			{
				cout << (head < tail ? deq[--tail] : -1) << '\n';
			}
			break;
			}
		}
		break;

		case 's':
		{
			cout << tail - head << '\n';
		}
		break;

		case 'e':
		{
			cout << (head == tail ? 1 : 0) << '\n';
		}
		break;

		case 'f':
		{
			cout << (head < tail ? deq[head] : -1) << '\n';
		}
		break;

		case 'b':
		{
			cout << (head < tail ? deq[tail - 1] : -1) << '\n';
		}
		break;
		}
	}

	return 0;
}