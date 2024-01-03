// 14:38,14:51
#include<bits/stdc++.h>
using namespace std;

set<int> s;
int M, x;
string command;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M;
  while (M--) {
    cin >> command;
    switch (command[1]) {
    case 'd'://add
    {
      cin >> x;
      s.insert(x);
    }break;

    case 'e'://remove
    {
      cin >> x;
      s.erase(x);
    }break;

    case 'h'://check
    {
      cin >> x;
      cout << (s.find(x) != s.end()) << '\n';
    }break;

    case 'o'://toggle
    {
      cin >> x;
      if (s.find(x) != s.end()) {
        s.erase(x);
      }
      else {
        s.insert(x);
      }
    }break;

    case 'l'://all
    {
      for (x = 1; x <= 20; ++x) {
        s.insert(x);
      }
    }break;

    case 'm'://empty
    {
      s.clear();
    }break;
    }
  }
}