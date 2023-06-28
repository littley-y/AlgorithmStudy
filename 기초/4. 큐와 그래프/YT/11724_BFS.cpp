#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1001;
int N, M, cnt;
bool visited[MAX];
vector<int> connected[1001];

void BFS(int start) {
  queue<int> Q;
  Q.push(start);
  visited[start] = true;

  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop();

    for (const auto &it : connected[curr]) {
      if (visited[it] == true)
        continue;
      Q.push(it);
      visited[it] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    connected[u].push_back(v);
    connected[v].push_back(u);
  }

  for (int i = 1; i <= N; i++) {
    if (visited[i] == false) {
      BFS(i);
      cnt++;
    }
  }
  cout << cnt << '\n';

  return 0;
}