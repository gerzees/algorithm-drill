#include<bits/stdc++.h>
using namespace std;

typedef struct { char value; int lc; int rc; } node;
node nodes[111];
int cnt_node = 1;
string expression;

int make_tree(int s, int e) {
  if (e - s == 1) {
    int cur_idx = cnt_node++;
    nodes[cur_idx].value = expression[s];

    return cur_idx;
  }

  vector<int> op_idx[2];

  for (int i = s; i < e; ++i) {

    if (expression[i] == '+' || expression[i] == '-') {
      op_idx[0].push_back(i);
      continue;
    }

    if (expression[i] == '*' || expression[i] == '/') {
      op_idx[1].push_back(i);
      continue;
    }

    if (expression[i] == '(') {
      int cnt = 1;
      do {
        ++i;

        if (expression[i] == '(') {
          ++cnt;
        }
        else if (expression[i] == ')') {
          --cnt;
        }
      } while (cnt > 0);
    }
  }

  if (op_idx[0].empty() && op_idx[1].empty()) {
    return make_tree(s + 1, e - 1);
  }

  int idx = op_idx[0].empty() == false ? op_idx[0].back() : op_idx[1].back();

  int cur_idx = cnt_node++;
  nodes[cur_idx].value = expression[idx];
  nodes[cur_idx].lc = make_tree(s, idx);
  nodes[cur_idx].rc = make_tree(idx + 1, e);

  return cur_idx;
}

char result[111];
int result_idx;

void lrv(int idx) {
  if (idx == 0) {
    return;
  }

  node& cur = nodes[idx];
  lrv(cur.lc);
  lrv(cur.rc);
  result[result_idx++] = cur.value;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> expression;

  int root_idx = make_tree(0, expression.length());
  lrv(root_idx);
  cout << result;
}