// 11:41 - 11:51 13:00-13:14
#include<bits/stdc++.h>
using namespace std;
string winner[] = { "CY", "SK" };
int main(void)
{
	int n;
	cin >> n;
	cout << winner[n % 2];

	return 0;
}