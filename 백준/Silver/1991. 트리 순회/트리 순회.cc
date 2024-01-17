//10:51, 11:53
#include<bits/stdc++.h>
using namespace std;

int N;
int l[27];
int r[27];
const int OFFSET = 'A' - 1;
void preorder(int cur) {
  cout << char(cur + OFFSET);
  if (l[cur] > 0) preorder(l[cur]);
  if (r[cur] > 0) preorder(r[cur]);
}
void inorder(char cur) {
  if (l[cur] > 0) inorder(l[cur]);
  cout << char(cur + OFFSET);
  if (r[cur] > 0) inorder(r[cur]);
}
void postorder(char cur) {
  if (l[cur] > 0)postorder(l[cur]);
  if (r[cur] > 0)postorder(r[cur]);
  cout << char(cur + OFFSET);
}


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0;i < N; ++i) {
    char cur,lc,rc;
    cin >> cur >> lc >> rc;
    l[cur - OFFSET] = lc - OFFSET;
    r[cur - OFFSET] = rc - OFFSET;
  }

  preorder(1);
  cout << '\n';
  inorder(1);
  cout << '\n';
  postorder(1);
}