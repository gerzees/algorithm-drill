// 16:08, 16:38
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int heap[100'005];
int sz = 0; // heap에 들어 있는 원소의 수

void swapAfterPushRecursive(int curr) {
  int parent = curr / 2;

  if (parent < 1)
    return;
  if (heap[parent] <= heap[curr])
    return;

  swap(heap[parent], heap[curr]);
  swapAfterPushRecursive(parent);
}
void swapAfterPopRecursive(int curr) {
  int LChild = 2 * curr;
  int RChild = 2 * curr + 1;

  if (LChild > sz)
    return;

  int minChild = LChild;

  if (RChild > sz) {
    if (heap[curr] <= heap[LChild])
      return;
  }
  else {
    if (heap[curr] <= heap[LChild] && heap[curr] <= heap[RChild])
      return;

    if (heap[RChild] < heap[LChild])
      minChild = RChild;
  }

  swap(heap[curr], heap[minChild]);
  swapAfterPopRecursive(minChild);
}

void push(int x) {
  ++sz;
  heap[sz] = x;
  swapAfterPushRecursive(sz);
}

int top() {
  return heap[1];
}

void pop() {
  swap(heap[1], heap[sz]);
  --sz;
  swapAfterPopRecursive(1);
}

int N;
int x;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while (N--) {
    cin >> x;

    if (x == 0) {
      if (sz == 0) {
        cout << 0 << '\n';
        continue;
      }

      cout << top() << '\n';
      pop();
    }
    else {
      push(x);
    }
  }
}