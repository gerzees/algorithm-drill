//16:48,17:10
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

pair<int, int> lines[1000000];
int main(void)
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> lines[i].X >> lines[i].Y;
	}

	sort(lines, lines + n);

	int len = 0;
	int curX = lines[0].X;
	int curY = lines[0].Y;
	for (int i = 1; i < n; ++i) {
		if (lines[i].Y <= curY) { // 포함
			continue;
		}
		if (lines[i].X <= curY && lines[i].Y > curY) {// 겹침 & 연장
			curY = lines[i].Y;
			continue;
		}
		//if (lines[i].X > curY) { // 안겹치는 선 새로 긋는다
		len += curY - curX;
		curX = lines[i].X;
		curY = lines[i].Y;
	}

	len += curY - curX;
	cout << len;

	return 0;
}