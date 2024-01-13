//8:40, 10:28
#include<bits/stdc++.h>
using namespace std;
/*
* 사람수 N 파티수 M
* 진실 아는 사람 수, 사람 번호([1..N]) ...
* (각 파티마다 오는 사람 수, 사람 번호...) ...
*
* 진실을 아는 참가하는 파티에서 진실 말함, 그럼 그 참가자들이 가는 파티에서도 진실을 말함
* 진실을 말해야하는 파티 전부 제외한 나머지가 거짓말 가능한 파티
* 노드: 각 파티
* 간선: 진실 듣는 사람 공통으로 가진 파티를 연결
*
* 답: 연결되지 않은 노드 개수= 거짓말 가능 파티 수
*
* 노드: 각 사람([1..50]), 각 파티([51..100])
* 간선: 참가자-파티
* 풀이: 그래프에서 진실은 퍼져나가고, 진실이 도달하지 못한 파티에서 거짓말 가능.
*/

int N, M;
const int PARTYSTART = 60;
vector<int> adj[111];
vector<bool> vis(111);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  int truthCnt;
  cin >> truthCnt;
  queue<int> q;
  while (truthCnt--) {
    int truth;
    cin >> truth;
    q.push(truth);
    vis[truth] = true;
  }

  for (int party = PARTYSTART;party < PARTYSTART + M;++party) {
    int participantCnt;
    cin >> participantCnt;
    while (participantCnt--) {
      int participant;
      cin >> participant;
      adj[party].push_back(participant);
      adj[participant].push_back(party);
    }
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int nxt : adj[cur]) {
      if (vis[nxt]) continue;

      q.push(nxt);
      vis[nxt] = true;
    }
  }

  int ans = 0;
  
  for (int party = PARTYSTART; party < M + PARTYSTART; ++party) {
    if (vis[party]) continue;

    ++ans;
  }

  cout << ans;
}