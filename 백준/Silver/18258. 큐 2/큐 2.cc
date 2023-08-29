#include <bits/stdc++.h>

using namespace std;

int Q[2000000]; //스택 터지나? 지역 변수로 선언하면 "종료되었습니다(코드: -1073741571개" 나오면서 프로그램 종료됨

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	//push,pop,size,empty,front,back
	//input integer: 1 .. 100,000
	int head = 0;
	int tail = 0;
	int N;// count command, <=2,000,000
	cin >> N;
	string command;

	for (int i = 0; i < N; ++i)
	{
		cin >> command;
		switch (command[0])
		{

		case 'p':
		{
			if (command[1] == 'u')//push
			{
				cin >> Q[tail++];
			}
			else//pop
			{
				cout << (head == tail ? -1 : Q[head++]) << '\n';
			}
		}
		break;

		case 's'://size
		{
			cout << tail - head << '\n';
		}
		break;

		case 'e'://empty
		{
			cout << (head == tail ? 1 : 0) << '\n';
		}
		break;

		case 'b'://back
		{
			cout << (head == tail ? -1 : Q[tail - 1]) << '\n';
		}
		break;

		case 'f'://front
		{
			cout << (head == tail ? -1 : Q[head]) << '\n';

		}
		break;
		}
	}

	return 0;
}