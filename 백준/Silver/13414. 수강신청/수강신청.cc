//19:43,20:00
#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
string waiting[500'000];
int k, l;

int main(void)
{
	cin >> k >> l;
	for(int i=0;i<l;++i){
		string studentNum;
		cin >> studentNum;
		mp[studentNum] = i;
	}

	for (auto& student : mp) {
		waiting[student.second] = student.first;
	}

	int cnt = 0;
	for (auto& studentNum : waiting) {
		if (studentNum != "") {
			cout << studentNum << '\n';
			++cnt;
			
			if (cnt == k) {
				return 0;
			}
		}

	}

	return 0;
}