//10:33,11:05
//14:05,15:47
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
string a, w, s;
int char_to_num[256];
vector<bool> chk(256);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  while (n--) {
    cin >> a >> w >> s;

    for (int i = 0; i < a.length(); ++i)
      char_to_num[a[i]] = i;

    vector<int> cnt_shift(a.length());

    if (w.length() == 1) {
      for (int i = 0; i < s.size(); ++i) {
        int shift = char_to_num[s[i]] - char_to_num[w[0]];

        if (shift < 0) shift += a.length();

        ++cnt_shift[shift];
      }
    }
    else {
      vector<int> target, text;
      target.reserve(w.length());
      text.reserve(s.length());

      for (int i = 0;i + 1 < w.length();++i) {
        int diff = char_to_num[w[i + 1]] - char_to_num[w[i]];

        if (diff < 0) diff += a.length();

        target.push_back(diff);
      }

      for (int i = 0;i + 1 < s.length();++i) {
        int diff = char_to_num[s[i + 1]] - char_to_num[s[i]];

        if (diff < 0) diff += a.length();

        text.push_back(diff);
      }

      vector<int> f(target.size());
      int j = 0;
      for (int i = 1; i < target.size(); ++i) {
        while (j > 0 && target[i] != target[j]) j = f[j - 1];

        if (target[i] == target[j]) f[i] = ++j;
      }

      j = 0;
      for (int i = 0; i < text.size(); ++i) {
        while (j > 0 && text[i] != target[j]) j = f[j - 1];

        if (text[i] == target[j]) ++j;

        if (j == target.size()) {
          j = f[j - 1];

          int shift = char_to_num[s[i + 1 - target.size()]] - char_to_num[w[0]];

          if (shift < 0) shift += a.length();

          ++cnt_shift[shift];
        }
      }
    }

    vector<int> ans;
    for (int shift = 0;shift < a.length(); ++shift) {
      if (cnt_shift[shift] == 1) ans.push_back(shift);
    }

    if (ans.size() == 0) {
      cout << "no solution\n";
    }
    else if (ans.size() == 1) {
      cout << "unique: " << ans[0] << '\n';
    }
    else {
      cout << "ambiguous: ";

      for (int shift : ans) cout << shift << ' ';

      cout << '\n';
    }
  }
}