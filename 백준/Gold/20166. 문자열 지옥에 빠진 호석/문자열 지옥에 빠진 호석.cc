//12:30,
//30*8*8*8*8
#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> ump;
const int M = 1'000'003;
const int a = 1'000;
const int EMPTY = -1;
const int OCCUPY = 0;
const int DUMMY = 1;
int status[M];
string key[M];
int val[M];

int my_hash(const string& k) {
	int h = 0;
	for (auto x : k)
		h = (h * a + x) % M;

	return h;
}

int find(const string& k) {
	int idx = my_hash(k);
	while (status[idx] != EMPTY) {
		if (status[idx] == OCCUPY && key[idx] == k) return idx;

		idx = (idx + 1) % M;
	}

	return -1;
}

void insert(const string& k, int v) {
	int idx = find(k);
	if (idx != -1) {
		val[idx] = v;
		return;
	}

	idx = my_hash(k);
	while (status[idx] == OCCUPY) idx = (idx + 1) % M;

	key[idx] = k;
	val[idx] = v;
	status[idx] = OCCUPY;
}

void erase(const string& k) {
	int idx = find(k);
	if (idx != -1) status[idx] = DUMMY;
}

string board[30];
int m, n, k;

int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };

char tmp[10];

void makeStr(int x, int y, int len) {
	if (len == 5) {
		return;
	}

	tmp[len] = board[x][y];

	//int v = 1;
	//int idx = find(tmp);
	//if (idx != -1) {
	//	v += val[idx];
	//}

	//insert(tmp, v);

	/*if (ump.find(tmp) == ump.end()) ump[tmp] = 1;
	else */++ump[tmp];

	for (int i = 0; i < 8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx == n)nx = 0;
		else if (nx == -1) nx = n - 1;
		if (ny == m)ny = 0;
		else if (ny == -1) ny = m - 1;

		makeStr(nx, ny, len + 1);
	}

	tmp[len] = '\0';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(status, status + M, EMPTY);

	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i) {
		cin >> board[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			makeStr(i, j, 0);
		}
	}

	while (k--) {
		string godStr;
		cin >> godStr;
		cout << ump[godStr] << '\n';
		//int idx = find(godStr);
		//if (idx == -1) cout << 0 << '\n';
		//else cout << val[idx] << '\n';
	}
}