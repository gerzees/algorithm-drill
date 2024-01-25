//7:45, 8:54
#include <bits/stdc++.h>

using namespace std;

unordered_map<string, unordered_set<string>> gen;
unordered_map<string, set<string>> adj;
unordered_map<string, bool> isRoot;
unordered_map<string, int> indegree;
int N, M;
string name[1'000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> name[i];
    gen.insert({ name[i],unordered_set<string>() });
    adj.insert({ name[i],set<string>() });
    isRoot.insert({ name[i],true });
    indegree.insert({ name[i],0 });
  }

  cin >> M;
  while (M--) {
    string ance, desc;
    cin >> desc >> ance;
    gen[ance].insert(desc);
    isRoot[desc] = false;
    ++indegree[desc];
  }

  vector<string> roots;
  sort(name, name + N);

  for (int i = 0;i < N; ++i) {
    if (!isRoot[name[i]]) continue;
    
    roots.push_back(name[i]);
    queue<string> q;
    q.push(name[i]);

    while (!q.empty()) {
      string cur = q.front(); 
      q.pop();

      for (auto& nxt : gen[cur]) {
        --indegree[nxt];

        if (indegree[nxt] == 0) {
          q.push(nxt);
          adj[cur].insert(nxt);
        }
      }
    }
  }

  cout << roots.size() << '\n';

  for (string& root : roots) {
    cout << root << ' ';
  }
  
  cout << '\n';
  
  for (int i = 0; i < N; ++i) {
    cout << name[i]<<' '<< adj[name[i]].size() << ' ';
  
    for (const string& child : adj[name[i]]) {
      cout << child << ' ';
    }
    
    cout << '\n';
  }
}