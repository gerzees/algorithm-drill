// 13:05,13:25
#include<bits/stdc++.h>
using namespace std;

int N, x;
int heap[100'001];
int sz = 1;

void push(int n) {
  int idx = sz++;
  heap[idx] = n;

  while (idx != 1) {
    int par = idx / 2;

    if (heap[par] >= heap[idx]) break;

    swap(heap[par], heap[idx]);
    idx = par;
  }
}

bool empty(void) {
  return sz == 1;
}

int top(void) {
  return heap[1];
}

void pop() {
  heap[1] = heap[--sz];
  int idx = 1;

  while (idx < sz) {
    int chi = idx * 2;
    
    if (chi >= sz) {
      break;
    }

    if (chi + 1 < sz && heap[chi + 1] > heap[chi]) {
      chi = chi + 1;
    }
      
    if (heap[idx] > heap[chi]) {
      break;
    }  
   
    swap(heap[idx], heap[chi]);
    idx = chi;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while (N--) {
    cin >> x;

    if (x != 0) { // 배열에 자연수 넣기
      push(x);
      continue;
    }

    //배열의 최대 출력, 제거
    if (empty()) {
      cout << 0 << '\n';
      continue;
    }

    cout << top() << '\n';
    pop();
  }
}