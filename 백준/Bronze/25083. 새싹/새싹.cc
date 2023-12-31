// 15:40 , 15:56
#include<bits/stdc++.h>
using namespace std;

string board[] = {
  "         ,r'\"7\n",
  "r`-_   ,'  ,/\n",
  " \\. \". L_r'\n",
  "   `~\\/\n",
  "      |\n",
  "      |"
};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (string& line : board) {
    cout << line;
  }
}